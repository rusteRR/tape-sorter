#include "sorter.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <set>
#include <string>
#include <utility>
#include "config.h"

namespace {
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<int> dist(1, INT32_MAX);
}  // namespace

tape_sorter::sorter::sorter(const std::string &input_file,
                            const std::string &output_file,
                            config conf)
    : input_tape(input_file), output_tape(output_file), cfg(std::move(conf)) {
}

void tape_sorter::sorter::sort() {
    build_sorted_tapes();
    std::set<std::pair<int, size_t>> heap;
    for (size_t i = 0; i < sorted_tapes.size(); ++i) {
        std::optional<int> read_num = sorted_tapes[i].read();
        if (!read_num.has_value()) {
            break;
        }
        heap.insert({read_num.value(), i});
    }

    while (!heap.empty()) {
        std::pair<int, size_t> max = *heap.begin();
        heap.erase(heap.begin());

        output_tape.write(max.first);

        if (!sorted_tapes[max.second].is_empty()) {
            std::optional<int> read_num = sorted_tapes[max.second].read();
            if (!read_num.has_value()) {
                break;
            }
            heap.insert({read_num.value(), max.second});
        }
    }
}

void tape_sorter::sorter::build_sorted_tapes() {
    int counter = 0;
    while (!input_tape.is_empty()) {
        std::vector<int> current_tape;
        std::string tmp_filename = get_filename(counter++);
        tape current_output_tape(tmp_filename);

        for (int i = 0; i < cfg.get_length_limit(); ++i) {
            std::optional<int> read_num = input_tape.read();
            if (!read_num.has_value()) {
                break;
            }
            current_tape.push_back(read_num.value());
        }
        std::sort(current_tape.begin(), current_tape.end());
        for (auto element : current_tape) {
            current_output_tape.write(element);
        }
        sorted_tapes.emplace_back(tmp_filename);
    }
}

std::string tape_sorter::sorter::get_filename(int counter) {
    std::string filename = cfg.get_tmp_dir() + "/" + std::to_string(dist(rng)) +
                           std::to_string(counter);
    tmp_filenames.push_back(filename);
    return filename;
}

tape_sorter::sorter::~sorter() {
    for (std::string &file_to_delete : tmp_filenames) {
        std::remove(file_to_delete.c_str());
    }
}
