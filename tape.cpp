#include "tape.h"
#include <iostream>

tape_sorter::tape::tape(const std::string &input_file) : tape_file(input_file) {
    if (!tape_file) {
        tape_file.open(input_file, std::fstream::out);
    }
}

std::optional<int> tape_sorter::tape::read() {
    int num;
    if (!(tape_file >> num)) {
        return std::nullopt;
    }
    return std::optional{num};
}

void tape_sorter::tape::write(int num) {
    tape_file << num << " ";
}

bool tape_sorter::tape::is_empty() {
    return tape_file.peek() == EOF;
}
