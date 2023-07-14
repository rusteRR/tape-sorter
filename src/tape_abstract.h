#ifndef TAPE_ABSTRACT_H_
#define TAPE_ABSTRACT_H_

#include <optional>

namespace tape_sorter {
class tape {
public:
    virtual std::optional<int> read() = 0;
    virtual void write(int num) = 0;
    virtual bool next() = 0;
    virtual bool prev() = 0;
    virtual bool has_next() = 0;

    virtual void reset_position() {
        while (prev()) {
        }
    }

    virtual ~tape() = default;
};
}  // namespace tape_sorter

#endif