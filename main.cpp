#include <iostream>
#include "config.h"
#include "sorter.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: <input_file> <output_file>" << std::endl;
        return EXIT_FAILURE;
    }

    tape_sorter::config cfg = tape_sorter::config();
    tape_sorter::sorter sorter = tape_sorter::sorter(argv[1], argv[2], cfg);
    sorter.sort();
}