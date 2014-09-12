#include "DerivativeCalculator.h"


using namespace calculator;

MathFunction DerivativeCalculator::calculateDerivative(const std::string& mathString) {
    MathFunction mathFunction = stringToFunction(mathString);

    return calculateDerivative(mathFunction);
}

MathFunction DerivativeCalculator::calculateDerivative(const MathFunction& mathFunction) {
    return mathFunction.takeDerivative();
}
