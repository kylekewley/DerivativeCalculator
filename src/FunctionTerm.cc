#include "FunctionTerm.h"

#include "Operator.h"
using namespace calculator;

FunctionTerm::FunctionTerm(const Constant &coefficient, FunctionType functionType,
        const Differentiable& arguments, const Constant& exponent):
    Term(coefficient, ' ', exponent), functionType(functionType), arguments(arguments) {
}

FunctionType FunctionTerm::getFunctionType() const {
    return functionType;
}

const Differentiable& FunctionTerm::getArguments() const {
    return arguments;
}

Differentiable FunctionTerm::operator+(const Term &rhs) const {
    return Operator(OpAddition, {*this, rhs});
}
Differentiable FunctionTerm::operator-(const Term &rhs) const {
    return Operator(OpSubtraction, {*this, rhs});
}
Differentiable FunctionTerm::operator*(const Term &rhs) const {
    return Operator(OpMultiplication, {*this, rhs});
}
Differentiable FunctionTerm::operator/(const Term &rhs) const {
    return Operator(OpDivision, {*this, rhs});
}

Differentiable FunctionTerm::operator+(const FunctionTerm &rhs) const {
    if (exponent == rhs.exponent && functionType == rhs.functionType &&
            arguments == rhs.arguments) {
        return FunctionTerm(coefficient+rhs.coefficient, functionType, arguments, exponent);
    }else {
        return Operator(OpAddition, {*this, rhs});
    }
}

Differentiable FunctionTerm::operator-(const FunctionTerm &rhs) const {
    if (exponent == rhs.exponent && functionType == rhs.functionType &&
            arguments == rhs.arguments) {
        return FunctionTerm(coefficient-rhs.coefficient, functionType, arguments, exponent);
    }else {
        return Operator(OpSubtraction, {*this, rhs});
    }
}
Differentiable FunctionTerm::operator*(const FunctionTerm &rhs) const {
    if (functionType == rhs.functionType && arguments == rhs.arguments) {
        return FunctionTerm(coefficient*rhs.coefficient, functionType, arguments, exponent + rhs.exponent);
    }else {
        return Operator(OpMultiplication, {*this, rhs});
    }
}

Differentiable FunctionTerm::operator/(const FunctionTerm &rhs) const {
    if (functionType == rhs.functionType && arguments == rhs.arguments) {
        return FunctionTerm(coefficient/rhs.coefficient, functionType, arguments, exponent - rhs.exponent);
    }else {
        return Operator(OpDivision, {*this, rhs});
    }
}

