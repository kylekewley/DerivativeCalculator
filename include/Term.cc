#include "Term.h"

#include "Constant.h"

using namespace calculator;
Term::Term(Constant &coefficient, char variable, Constant &exponent):
    coefficient(coefficient), variable(variable), exponent(exponent) {
}

Term::Term(double coefficient, char variable, double exponent):
    coefficient(Constant(coefficient)), variable(variable), exponent(Constant(exponent)) {
}

Differentiable Term::derivative() const {
    Constant newExponent = exponent - Constant(1);
    Constant newCoef = coefficient * exponent;

    return Term(newCoef, variable, newExponent);
}
