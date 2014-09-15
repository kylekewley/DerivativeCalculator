#ifndef CONSTANT_H
#define CONSTANT_H

#include "Differentiable.h"

namespace calculator {

    class Term;
    class FunctionTerm;
    class Constant : public Differentiable {
        public:

        Constant(int32_t value);
        Constant(double value);
        Constant(int32_t numerator, int32_t denominator);
        Constant(double numerator, int32_t denominator);

        virtual Differentiable derivative() const;

        Constant operator+(const Constant &rhs) const;
        Constant operator-(const Constant &rhs) const;
        Constant operator*(const Constant &rhs) const;
        Constant operator/(const Constant &rhs) const;

        bool operator==(const Constant &rhs) const;

        Differentiable operator+(const Term &rhs) const;
        Differentiable operator-(const Term &rhs) const;
        Differentiable operator*(const Term &rhs) const;
        Differentiable operator/(const Term &rhs) const;

        int32_t getDenominator() const;
        double getNumerator() const;
        bool isDecimal() const;

        private:
        //Can be a double or an int32_t
        double numerator;
        int32_t denominator;

        //If true, use numerator.decimal
        bool decimal;

        static bool isInteger(double value);
    };
}

#endif
