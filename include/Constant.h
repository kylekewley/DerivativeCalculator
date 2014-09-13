#ifndef CONSTANT_H
#define CONSTANT_H

#include "Differentiable.h"

namespace calculator {
    typedef union number {
        number(int32_t value): integer(value) {};
        number(float value): decimal(value) {};
        int32_t integer;
        float decimal;
    }number;

    class Constant : public Differentiable {
        public:

        Constant(int32_t value);
        Constant(float value);
        Constant(int32_t numerator, int32_t denominator);

        virtual Differentiable derivative() const;

        private:
        //Can be a double or an int32_t
        number numerator;
        int32_t denominator;

        //If true, use numerator.decimal
        bool isDecimal;
    };
}

#endif
