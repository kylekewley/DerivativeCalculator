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
        Operator(const OperatorChar opChar, const std::vector<std::shared_ptr<Differentiable>> children);

        /// Operations ///
        virtual std::shared_ptr<Differentiable> derivative() const;

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
        static std::shared_ptr<Differentiable> sumRule(Differentiable &leftOperand,
                Differentiable &rightOperand);

        /**
         * Returns the derivative of leftOperand - rightOperand.
         *
         * @param   leftOperand The operand on the left side of the operator.
         * @param   rightOperand The Operand on the right side of the operator.
         *
         * @return  A Differentiable object. The underlying class is Operator.
         */
        static std::shared_ptr<Differentiable> differenceRule(Differentiable& leftOperand,
                Differentiable& rightOperand);

        /**
         * Returns the derivative of leftOperand * rightOperand.
         *
         * @param   leftOperand The operand on the left side of the operator.
         * @param   rightOperand The Operand on the right side of the operator.
         *
         * @return  A Differentiable object. The underlying class is Operator.
         */
        static std::shared_ptr<Differentiable> productRule(Differentiable& leftOperand,
                Differentiable& rightOperand);

        /**
         * Returns the derivative of leftOperand / rightOperand.
         *
         * @param   leftOperand The operand on the left side of the operator.
         * @param   rightOperand The Operand on the right side of the operator.
         *
         * @return  A Differentiable object. The underlying class is Operator.
         */
        static std::shared_ptr<Differentiable> quotientRule(Differentiable& numerator,
                Differentiable& denominator);


        const std::vector<std::shared_ptr<Differentiable>> children;

        const OperatorChar opChar;
        const OperatorMetaData metaData;
    };
}

#endif
