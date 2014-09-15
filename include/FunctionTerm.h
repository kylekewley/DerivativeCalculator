#ifndef FUNCTION_TERM_H
#define FUNCTION_TERM_H

#include "Term.h"

#include "Constant.h"
#include "Differentiable.h"
namespace calculator {
    typedef enum {
        FunctionX,
        Sin,
        Cos,
        Tan,
    }FunctionType;

    class FunctionTerm : public Term {
        public:
        FunctionTerm(const Constant &coefficient, FunctionType functionType,
                const Differentiable& arguments, const Constant& exponent);


        FunctionType getFunctionType() const;
        const Differentiable& getArguments() const;

        virtual Differentiable operator+(const Term &rhs) const;
        virtual Differentiable operator-(const Term &rhs) const;
        virtual Differentiable operator*(const Term &rhs) const;
        virtual Differentiable operator/(const Term &rhs) const;

        virtual Differentiable operator+(const FunctionTerm &rhs) const;
        virtual Differentiable operator-(const FunctionTerm &rhs) const;
        virtual Differentiable operator*(const FunctionTerm &rhs) const;
        virtual Differentiable operator/(const FunctionTerm &rhs) const;

        private:
        FunctionType functionType;
        Differentiable arguments;
    };

}

#endif

