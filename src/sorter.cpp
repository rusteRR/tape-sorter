#include "sorter.h"
#include <algorithm>
#include <chrono>
#include <set>
#include <string>

tape_sorter::sorter::sorter(std::shared_ptr<tape> input_tape_,
                            std::shared_ptr<tape> output_tape_,
                            std::shared_ptr<tape_fabric_interface> fabric_,
                            config cfg_)
    : input_tape(std::move(input_tape_)),
      output_tape(std::move(output_tape_)),
      fabric(std::move(fabric_)),
      cfg(cfg_) {
}

void tape_sorter::sorter::sort() {
    build_sorted_tapes();
    std::set<std::pair<int, size_t>> heap;
    for (size_t i = 0; i < sorted_tapes.size(); ++i) {
        std::optional<int> read_num = sorted_tapes[i]->read();
        if (!read_num.has_value()) {
            break;
        }
        heap.insert({read_num.value(), i});
    }

    while (!heap.empty()) {
        auto [max_element, tape_index] = *heap.begin();
        heap.erase(heap.begin());

        output_tape->write(max_element);

        std::optional<int> read_num = sorted_tapes[tape_index]->read();
        if (!read_num.has_value()) {
            break;
        }
        heap.insert({read_num.value(), tape_index});
    }
}

void tape_sorter::sorter::build_sorted_tapes() {
    while (input_tape->has_next()) {
        std::vector<int> current_tape;

        std::shared_ptr<tape> current_output_tape = fabric->get_tape();

        for (int i = 0; i < cfg.get_length_limit(); ++i) {
            std::optional<int> read_num = input_tape->read();
            if (!read_num.has_value()) {
                break;
            }
            current_tape.push_back(read_num.value());
        }
        std::sort(current_tape.begin(), current_tape.end());
        for (auto element : current_tape) {
            current_output_tape->write(element);
        }
        current_output_tape->reset_position();
        sorted_tapes.push_back(current_output_tape);
    }
}
