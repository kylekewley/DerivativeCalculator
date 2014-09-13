#include "Constant.h"


using namespace calculator;

Constant::Constant(int32_t value):
    numerator(value), denominator(1), decimal(false) {
}

Constant::Constant(double value):
    numerator(value), denominator(1), decimal(true) {
}

Constant::Constant(int32_t numerator, int32_t denominator):
    numerator(numerator), denominator(denominator), decimal(false) {
}

Differentiable Constant::derivative() const {
    //Derivative of a constant is zero
    return Constant(0);
}

int32_t Constant::getDenominator() const {
    return denominator;
}
double Constant::getNumerator() const {
    return numerator;
}
bool Constant::isDecimal() const {
    return decimal;
}


Constant Constant::operator+(const Constant &rhs) {
    int32_t newDenominator = denominator * rhs.denominator;
    double newNumerator = numerator*rhs.denominator + rhs.numerator*denominator;
    if (rhs.decimal || decimal) {
        return Constant(newNumerator/newDenominator);
    }else {
        return Constant(static_cast<int32_t>(newNumerator), newDenominator);
    }
}

Constant Constant::operator-(const Constant &rhs) {
    int32_t newDenominator = denominator * rhs.denominator;
    double newNumerator = numerator*rhs.denominator - rhs.numerator*denominator;
    if (rhs.decimal || decimal) {
        return Constant(newNumerator/newDenominator);
    }else {
        return Constant(static_cast<int32_t>(newNumerator), newDenominator);
    }
}

Constant Constant::operator*(const Constant &rhs) {
    return Constant()
}

Constant Constant::operator/(const Constant &rhs) {
}

Constant operator--() {
}
Constant operator++() {
}
