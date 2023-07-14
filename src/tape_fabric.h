#ifndef TAPE_FABRIC_H_
#define TAPE_FABRIC_H_

#include <string>
#include <vector>
#include "tape_fabric_abstract.h"

namespace tape_sorter {
class tape_fabric : public tape_fabric_interface {
public:
    [[nodiscard]] std::shared_ptr<tape> get_tape() override;
    ~tape_fabric() override;

private:
    static const inline std::string tmp_dir = ".";
    std::vector<std::string> tmp_filenames;

    std::string get_filename();
};
}  // namespace tape_sorter

#endif