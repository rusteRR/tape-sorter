#ifndef SORTER_H_
#define SORTER_H_

#include <vector>
#include "config.h"
#include "tape.h"

namespace tape_sorter {
class sorter {
public:
    sorter(const std::string &input_file,
           const std::string &output_file,
           config cfg);

    void sort();

    ~sorter();

private:
    void build_sorted_tapes();
    std::string get_filename(int counter);

    tape_sorter::tape input_tape;
    tape_sorter::tape output_tape;
    config cfg;
    std::vector<tape_sorter::tape> sorted_tapes;
    std::vector<std::string> tmp_filenames;
};
}  // namespace tape_sorter

#endif