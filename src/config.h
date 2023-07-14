#ifndef CONFIG_H_
#define CONFIG_H_

#include <fstream>
#include <string>

namespace tape_sorter {
class config {
public:
    config();

    config(int length_limit, int read_delay, int write_delay, int move_delay);

    int get_length_limit();
    int get_read_delay();
    int get_write_delay();
    int get_move_delay();

private:
    int length_limit;
    int read_delay;
    int write_delay;
    int move_delay;
};
}  // namespace tape_sorter

#endif