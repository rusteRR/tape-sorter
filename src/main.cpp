#include <iostream>
#include "config.h"
#include "sorter.h"
#include "tape_file.h"
#include "tape_fabric.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: <input_file> <output_file>" << std::endl;
        return EXIT_FAILURE;
    }

    tape_sorter::config cfg = tape_sorter::config();
    tape_sorter::sorter sorter = tape_sorter::sorter(std::make_shared<tape_sorter::tape_file>(argv[1]),
                                                     std::make_shared<tape_sorter::tape_file>(argv[2]),
                                                     std::make_shared<tape_sorter::tape_fabric>(),
                                                     cfg);
    sorter.sort();
}