#ifndef CONFIG_H_
#define CONFIG_H_

#include <fstream>
#include <string>

namespace tape_sorter {
class config {
public:
    config();

    config(int length_limit,
           int read_delay,
           int write_delay,
           int move_delay,
           const std::string &tmp_dir);

    int get_length_limit();

    int get_read_delay();

    int get_write_delay();

    int get_move_delay();

    const std::string &get_tmp_dir();

private:
    int length_limit;
    int read_delay;
    int write_delay;
    int move_delay;
    std::string tmp_dir;
};
}  // namespace tape_sorter

#endif