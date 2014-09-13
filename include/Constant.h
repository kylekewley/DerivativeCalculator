#ifndef CONSTANT_H
#define CONSTANT_H

#include "Differentiable.h"

namespace calculator {
//    typedef union number {
//        number(int32_t value): integer(value) {};
//        number(float value): decimal(value) {};
//        number(){};
//        int32_t integer;
//        float decimal;
//    }number;

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
