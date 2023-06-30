#ifndef TAPE_H_
#define TAPE_H_

#include <fstream>
#include <optional>
#include <string>
#include <utility>

namespace tape_sorter {
class tape {
public:
    explicit tape(const std::string &input_file);

    std::optional<int> read();

    void write(int num);

    bool is_empty();

private:
    std::fstream tape_file;
};
}  // namespace tape_sorter

#endif