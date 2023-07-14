#include "tape_file.h"
#include <iostream>

tape_sorter::tape_file::tape_file(const std::string &input_file)
    : file(input_file), current_pos(0) {
    if (!file) {
        file.open(input_file,
                  std::fstream::in | std::fstream::out | std::fstream::trunc);
    }
}

std::optional<int> tape_sorter::tape_file::read() {
    int num;
    if (!(file >> num)) {
        return std::nullopt;
    }
    current_pos++;
    return std::optional{num};
}

void tape_sorter::tape_file::write(int num) {
    file << num << " ";
    current_pos++;
    file.flush();
}

bool tape_sorter::tape_file::next() {
    if (int tmp; has_next()) {
        file >> tmp;
        current_pos++;
    }
    return has_next();
}

bool tape_sorter::tape_file::prev() {
    if (current_pos == 0) {
        return false;
    }
    reset_position();
    for (int i = 1; i < current_pos; ++i) {
        int tmp;
        file >> tmp;
    }
    current_pos--;
    return true;
}

bool tape_sorter::tape_file::has_next() {
    return file.peek() != EOF;
}
void tape_sorter::tape_file::reset_position() {
    file.seekg(0);
}

tape_sorter::tape_file::~tape_file() = default;
