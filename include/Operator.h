#ifndef OPERATOR_H
#define OPERATOR_H

#include <vector>
#include <map>

#include "Operand.h"

namespace calculator {

    typedef enum {
        AssociativityRight,
        AssociativityLeft
    }Associativity;

    typedef enum {
        ArityUnary,
        ArityBinary
    }Arity;

    typedef struct OperatorMetaData {
        OperatorMetaData(const Arity arity, const Associativity assoc, const int precedence):
        arity(arity), assoc(assoc), precedence(precedence){};

        OperatorMetaData(): arity(ArityUnary), assoc(AssociativityLeft), precedence(0){};

        Arity arity;
        Associativity assoc;
        int precedence;
    }OperatorMetaData;

    typedef enum {
        OpNone = ' ',
        OpAddition = '+',
        OpSubtraction = '-',
        OpMultiplication = '*',
        OpDivision = '/',
        OpExponent = '^'
    }OperatorChar;

    class Operator : public Differentiable {
        public:
        /// Constructors ///
        /**
         * Creates a new empty operator.
         */
        Operator();

        /**
         * Creates a new operator with the given operator and operands
         *
         * @param operatorChar  The character representation of the operator.
         * @param children      A vector containing the children of the operator.
         */
        Operator(const OperatorChar opChar, const std::vector<Differentiable> children);

        /// Operations ///
        virtual Differentiable derivative() const;

        private:

        /**
         * Creates the static operaterMetaData map. The map associates the
         * operater key with the OperatorMetaData value. The OperatorMetaData
         * includes precedence, arity, and associativity.
         */
        static std::map<OperatorChar, OperatorMetaData> createOperatorMap();

        /**
         * Used to determine the associativity, arity, and precedence of each
         * operator.
         */
        static std::map<OperatorChar, OperatorMetaData> operatorMetaData;

        /**
         * Returns the derivative of leftOperand + rightOperand.
         *
         * @param   leftOperand The operand on the left side of the operator.
         * @param   rightOperand The Operand on the right side of the operator.
         *
         * @return  A Differentiable object. The underlying class is Operator.
         */
        static Differentiable sumRule(Differentiable &leftOperand,
                Differentiable &rightOperand);

        /**
         * Returns the derivative of leftOperand - rightOperand.
         *
         * @param   leftOperand The operand on the left side of the operator.
         * @param   rightOperand The Operand on the right side of the operator.
         *
         * @return  A Differentiable object. The underlying class is Operator.
         */
        static Differentiable differenceRule(Differentiable& leftOperand,
                Differentiable& rightOperand);

        /**
         * Returns the derivative of leftOperand * rightOperand.
         *
         * @param   leftOperand The operand on the left side of the operator.
         * @param   rightOperand The Operand on the right side of the operator.
         *
         * @return  A Differentiable object. The underlying class is Operator.
         */
        static Differentiable productRule(Differentiable& leftOperand,
                Differentiable& rightOperand);

        /**
         * Returns the derivative of numerator / denominator.
         *
         * @param   leftOperand The operand on the left side of the operator.
         * @param   rightOperand The Operand on the right side of the operator.
         *
         * @return  A Differentiable object. The underlying class is Operator.
         */
        static Differentiable quotientRule(Differentiable& numerator,
                Differentiable& denominator);

        /**
         * Returns the derivative of term^exponent. Both term and exponent
         * should have the variable x.
         *
         * @param   leftOperand The operand on the left side of the operator.
         * @param   rightOperand The Operand on the right side of the operator.
         *
         * @return  A Differentiable object. The underlying class is Operator.
         */
        //static Differentiable powerRule(Differentiable& term,
        //        Differentiable& exponent);

        /**
         * Returns the derivative of term^exponent. Term should contain and x
         * and exponent should be a constant.
         *
         * @param   leftOperand The operand on the left side of the operator.
         * @param   rightOperand The Operand on the right side of the operator.
         *
         * @return  A Differentiable object. The underlying class is Operator.
         */
        //static Differentiable powerRule(Differentiable& term,
        //        Constant& exponent);
        const std::vector<Differentiable> children;

        const OperatorChar opChar;
        const OperatorMetaData metaData;
    };
}

#endif
