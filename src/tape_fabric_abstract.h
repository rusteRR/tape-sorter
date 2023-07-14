#ifndef TAPE_FABRIC_ABSTRACT_H_
#define TAPE_FABRIC_ABSTRACT_H_

#include <memory>
#include "tape_abstract.h"

namespace tape_sorter {
class tape_fabric_interface {
public:
    [[nodiscard]] virtual std::shared_ptr<tape> get_tape() = 0;
    virtual ~tape_fabric_interface() = default;
};

}  // namespace tape_sorter

#endif