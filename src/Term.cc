#include "Term.h"
#include "FunctionTerm.h"

#include "Operator.h"

using namespace calculator;
Term::Term(const Constant &coefficient, const char variable, const Constant &exponent):
    coefficient(coefficient), variable(variable), exponent(exponent) {
}

Term::Term(const double coefficient, const char variable, const double exponent):
    coefficient(Constant(coefficient)), variable(variable), exponent(Constant(exponent)) {
}

Differentiable Term::derivative() const {
    Constant newExponent = exponent - Constant(1);
    Constant newCoef = coefficient * exponent;

    return Term(newCoef, variable, newExponent);
}

Differentiable Term::operator+(const Constant &rhs) const {
    return Operator(OpAddition, {*this, rhs});
}

Differentiable Term::operator-(const Constant &rhs) const {
    return Operator(OpSubtraction, {*this, rhs});
}

Term Term::operator*(const Constant &rhs) const {
    return Term(coefficient*rhs, variable, exponent);
}

Term Term::operator/(const Constant &rhs) const {
    return Term(coefficient/rhs, variable, exponent);
}

Differentiable Term::operator+(const Term &rhs) const {
    if (rhs.variable == variable && rhs.exponent == exponent) {
        return Term(coefficient + rhs.coefficient, variable, exponent);
    }else {
        return Operator(OpAddition, {*this, rhs});
    }
}

Differentiable Term::operator-(const Term &rhs) const {
    if (rhs.variable == variable && rhs.exponent == exponent) {
        return Term(coefficient - rhs.coefficient, variable, exponent);
    }else {
        return Operator(OpSubtraction, {*this, rhs});
    }
}

Differentiable Term::operator*(const Term &rhs) const {
    if (rhs.variable == variable) {
        return Term(coefficient * rhs.coefficient, variable, exponent + rhs.exponent);
    }else {
        return Operator(OpMultiplication, {*this, rhs});
    }
}

Differentiable Term::operator/(const Term &rhs) const {
    if (rhs.variable == variable) {
        return Term(coefficient / rhs.coefficient, variable, exponent - rhs.exponent);
    }else {
        return Operator(OpDivision, {*this, rhs});
    }
}

Differentiable Term::operator+(const FunctionTerm &rhs) const {
    return Operator(OpAddition, {*this, rhs});
}

Differentiable Term::operator-(const FunctionTerm &rhs) const {
    return Operator(OpSubtraction, {*this, rhs});
}

Differentiable Term::operator*(const FunctionTerm &rhs) const {
    return Operator(OpMultiplication, {*this, rhs});
}

Differentiable Term::operator/(const FunctionTerm &rhs) const {
    return Operator(OpDivision, {*this, rhs});
}

const Constant& Term::getCoefficient() const {
    return coefficient;
}

char Term::getVariable() const {
    return variable;
}

const Constant& Term::getExponent() const {
    return exponent;
}

