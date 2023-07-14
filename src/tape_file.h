#ifndef TAPE_H_
#define TAPE_H_

#include <fstream>
#include <memory>
#include <optional>
#include <string>
#include <utility>
#include "tape_abstract.h"

namespace tape_sorter {
class tape_file : public tape {
public:
    explicit tape_file(const std::string &input_file);

    std::optional<int> read() override;
    void write(int num) override;
    bool next() override;
    bool prev() override;
    bool has_next() override;
    void reset_position() override;

    ~tape_file() override;

private:
    std::fstream file;
    size_t current_pos;
};
}  // namespace tape_sorter

#endif