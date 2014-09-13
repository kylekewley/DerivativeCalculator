#ifndef TERM_H
#define TERM_H

#include "Differentiable.h"

#include "Constant.h"

namespace calculator {
    /**
     * A simple polynomial term.
     * In the form coefficient*x^exponent.
     * Where coefficient and exponent are constants.
     */
    class Term : public Differentiable {
        public:
        Term(Constant &coefficient, char variable, Constant &exponent);
        Term(double coefficient, char variable, double exponent);

        virtual Differentiable derivative() const;

        private:
        Constant coefficient;
        char variable;
        Constant exponent;
    };

}

#endif
