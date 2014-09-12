#ifndef MATH_FUNCTION_h
#define MATH_FUNCTION_h

#include <vector>

#include "Operator.h"
#include "Operand.h"

namespace calculator {
    class MathFunction {
        public:
        MathFunction takeDerivative() const;


        private:
        Operator root;


    };
}


#endif
