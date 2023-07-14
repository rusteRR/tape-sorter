#include "config.h"

tape_sorter::config::config() {
    std::ifstream ifstream;
    ifstream.open("config.txt");
    if (!ifstream.is_open()) {
        return;
    }
    ifstream >> length_limit >> read_delay >> write_delay >> move_delay;
}

tape_sorter::config::config(int length_limit,
                            int read_delay,
                            int write_delay,
                            int move_delay)
    : length_limit(length_limit),
      read_delay(read_delay),
      write_delay(write_delay),
      move_delay(move_delay) {
}

int tape_sorter::config::get_length_limit() {
    return length_limit;
}

int tape_sorter::config::get_read_delay() {
    return read_delay;
}

int tape_sorter::config::get_write_delay() {
    return write_delay;
}

int tape_sorter::config::get_move_delay() {
    return move_delay;
}
