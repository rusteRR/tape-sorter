#ifndef SORTER_H_
#define SORTER_H_

#include <memory>
#include <vector>
#include "config.h"
#include "tape_abstract.h"
#include "tape_fabric_abstract.h"

namespace tape_sorter {
class sorter {
public:
    sorter(std::shared_ptr<tape> input_tape_,
           std::shared_ptr<tape> output_tape_,
           std::shared_ptr<tape_fabric_interface> fabric,
           config cfg);

    void sort();

private:
    void build_sorted_tapes();

    std::shared_ptr<tape> input_tape;
    std::shared_ptr<tape> output_tape;
    std::shared_ptr<tape_fabric_interface> fabric;
    config cfg;
    std::vector<std::shared_ptr<tape>> sorted_tapes;
};
}  // namespace tape_sorter

#endif