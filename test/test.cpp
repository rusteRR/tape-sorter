#include <tape_fabric.h>
#include <iostream>
#include <random>
#include <memory>
#include "config.h"
#include "sorter.h"
#include "tape_file.h"

namespace test_utils {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(1, INT32_MAX);

    void generate_input(long long numbers_in_tape, const std::string& filename) {
        std::fstream file(filename);
        if (!file) {
            file.open(filename, std::fstream::out);
        }
        for (long long i = 0; i < numbers_in_tape; ++i) {
            file << dist(rng) << " ";
        }
    }
}

void single_block_test() {
    std::string input_filename = "test/" + std::to_string(test_utils::dist(test_utils::rng));
    std::string output_filename = input_filename + ".out";
    test_utils::generate_input(1e5, input_filename);
    tape_sorter::config cfg(1e5, 1, 1, 1);
    tape_sorter::sorter sorter(std::make_shared<tape_sorter::tape_file>(input_filename),
                               std::make_shared<tape_sorter::tape_file>(output_filename),
                               std::make_shared<tape_sorter::tape_fabric>(),
                               cfg);
    sorter.sort();

    std::ifstream f(output_filename);
    int prev = INT32_MIN;
    int cur;
    while (f >> cur) {
        if (cur >= prev) {
            continue;
        }
        std::cout << "single_block_test: failed" << std::endl;
        return;
    }

    std::remove(output_filename.c_str());
    std::remove(input_filename.c_str());
    std::cout << "single_block_test: ok" << std::endl;
}

void sort_works_test() {
    std::string input_filename = "test/" + std::to_string(test_utils::dist(test_utils::rng));
    std::string output_filename = input_filename + ".out";
    test_utils::generate_input(1e4, input_filename);
    tape_sorter::config cfg(1e3, 1, 1, 1);
    tape_sorter::sorter sorter(std::make_shared<tape_sorter::tape_file>(input_filename),
                               std::make_shared<tape_sorter::tape_file>(output_filename),
                               std::make_shared<tape_sorter::tape_fabric>(),
                               cfg);
    sorter.sort();

    std::ifstream f(output_filename);
    int prev = INT32_MIN;
    int cur;
    while (f >> cur) {
        if (cur >= prev) {
            continue;
        }
        std::cout << "sort_works_test: failed" << std::endl;
        return;
    }

    std::remove(output_filename.c_str());
    std::remove(input_filename.c_str());
    std::cout << "sort_works_test: ok" << std::endl;
}

#ifdef HUGE_TEST

void big_input_test() {
    std::string input_filename = "test/" + std::to_string(test_utils::dist(test_utils::rng));
    std::string output_filename = input_filename + ".out";
    test_utils::generate_input(1e8 + 1, input_filename);
    tape_sorter::config cfg(100000, 1, 1, 1);
    tape_sorter::sorter sorter(std::make_shared<tape_sorter::tape_file>(input_filename),
                               std::make_shared<tape_sorter::tape_file>(output_filename),
                               std::make_shared<tape_sorter::tape_fabric>(),
                               cfg);
    sorter.sort();

    std::ifstream f(output_filename);
    int prev = INT32_MIN;
    int cur;
    while (f >> cur) {
        if (cur >= prev) {
            continue;
        }
        std::cout << "big_input_test: failed" << std::endl;
        return;
    }

    std::remove(output_filename.c_str());
    std::remove(input_filename.c_str());
    std::cout << "big_input_test: ok" << std::endl;
}

#endif

int main() {
    single_block_test();
    sort_works_test();
    #ifdef HUGE_TEST
    big_input_test();
    #endif
}