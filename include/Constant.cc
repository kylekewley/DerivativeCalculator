#include "Constant.h"

#include "math.h"


using namespace calculator;

Constant::Constant(int32_t value):
    numerator(value), denominator(1), decimal(false) {
}

Constant::Constant(double value):
    numerator(value), denominator(1), decimal(true) {
    if (isInteger(value)) {
        decimal = false;
    }
}

Constant::Constant(int32_t numerator, int32_t denominator):
    numerator(numerator), denominator(denominator), decimal(false) {
}

Constant::Constant(double numerator, int32_t denominator) {
    if (isInteger(numerator)) {
        decimal = false;
        this->numerator = numerator;
        this->denominator = denominator;
    }else {
        decimal = true;
        this->numerator = numerator / denominator;
        this->denominator = 1;
    }
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


Constant Constant::operator+(const Constant &rhs) const{
    int32_t newDenominator = denominator * rhs.denominator;
    double newNumerator = numerator*rhs.denominator + rhs.numerator*denominator;
    if (rhs.decimal || decimal) {
        return Constant(newNumerator/newDenominator);
    }else {
        return Constant(newNumerator, newDenominator);
    }
}

Constant Constant::operator-(const Constant &rhs) const {
    int32_t newDenominator = denominator * rhs.denominator;
    double newNumerator = numerator*rhs.denominator - rhs.numerator*denominator;
    if (rhs.decimal || decimal) {
        return Constant(newNumerator/newDenominator);
    }else {
        return Constant(newNumerator, newDenominator);
    }
}

Constant Constant::operator*(const Constant &rhs) const {
    if (rhs.decimal || decimal) {
        return Constant((numerator*rhs.numerator)/(denominator*rhs.denominator));
    }else {
        return Constant(numerator*rhs.numerator, denominator*rhs.denominator);
    }
}

Constant Constant::operator/(const Constant &rhs) const {
    if (rhs.decimal || decimal) {
        return Constant((numerator*rhs.denominator)/(denominator*rhs.numerator));
    }else {
        return Constant(numerator*rhs.numerator, denominator*rhs.denominator);
    }
}


bool Constant::isInteger(double value) {
    return value == floor(value);
}

