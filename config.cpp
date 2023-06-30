#include "config.h"

tape_sorter::config::config() {
    std::ifstream ifstream;
    ifstream.open("config.txt");
    ifstream >> length_limit >> read_delay >> write_delay >> move_delay >>
        tmp_dir;
}

tape_sorter::config::config(int length_limit,
                            int read_delay,
                            int write_delay,
                            int move_delay,
                            const std::string &tmp_dir)
    : length_limit(length_limit),
      read_delay(read_delay),
      write_delay(write_delay),
      move_delay(move_delay),
      tmp_dir(tmp_dir) {
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

const std::string &tape_sorter::config::get_tmp_dir() {
    return tmp_dir;
}
