#ifndef DERIVATIVE_CALCULATOR_h
#define DERIVATIVE_CALCULATOR_h

#include <string>

#include "MathFunction.h"


namespace calculator {
    class DerivativeCalculator {
        public:

        /**
         * Calculate the derivative of a string input.
         *
         * @param mathString A string representing a mathematical function.
         *
         * @return The derivative of the input string function.
         */
        static MathFunction calculateDerivative(const std::string& mathString);

        /**
         * Calculate the derivative of a function.
         *
         * @param mathFunction A math function object to take the derivative of.
         *
         * @return The derivative of the input function.
         */
        static MathFunction calculateDerivative(const MathFunction& mathFunction);

        /**
         * Convert a string to a math function.
         *
         * @param mathString The string to convert.
         *
         * @return  A math function object representing the string.
         */
        static MathFunction stringToFunction(const std::string& mathString);

    };
}
#endif
