#include "Constant.h"


using namespace calculator;

Constant::Constant(int32_t value):
    numerator(value), denominator(1), isDecimal(false) {
}

Constant::Constant(float value):
    numerator(value), denominator(1), isDecimal(true) {
    numerator.decimal = value;
}

Constant::Constant(int32_t numerator, int32_t denominator):
    numerator(numerator), denominator(denominator), isDecimal(false) {
}

Differentiable Constant::derivative() const {
    //Derivative of a constant is zero
    return Constant(0);
}
