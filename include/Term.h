#ifndef TERM_H
#define TERM_H

#include "Constant.h"
#include "Differentiable.h"

namespace calculator{
    /**
     * A simple polynomial term.
     * In the form coefficient*x^exponent.
     * Where coefficient and exponent are constants.
     */
    class Term : public Differentiable {

        public:
        Term(const Constant& coefficient, const char variable, const Constant& exponent);
        Term(const double coefficient, const char variable, const double exponent);

        virtual Differentiable derivative() const;

        const Constant& getCoefficient() const;
        char getVariable() const;
        const Constant& getExponent() const;

        Differentiable operator+(const Constant &rhs) const;
        Differentiable operator-(const Constant &rhs) const;
        Term operator*(const Constant &rhs) const;
        Term operator/(const Constant &rhs) const;

        virtual Differentiable operator+(const Term &rhs) const;
        virtual Differentiable operator-(const Term &rhs) const;
        virtual Differentiable operator*(const Term &rhs) const;
        virtual Differentiable operator/(const Term &rhs) const;

        virtual Differentiable operator+(const FunctionTerm &rhs) const;
        virtual Differentiable operator-(const FunctionTerm &rhs) const;
        virtual Differentiable operator*(const FunctionTerm &rhs) const;
        virtual Differentiable operator/(const FunctionTerm &rhs) const;

        protected:
        Constant coefficient;
        char variable;
        Constant exponent;
    };

}

#endif
