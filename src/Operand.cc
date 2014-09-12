#include "Operand.h"

#include <memory>

using namespace calculator;


std::shared_ptr<Differentiable> Differentiable::derivative() const {

    return std::shared_ptr<Operand>();
}
