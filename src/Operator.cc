#include "Operator.h"

#include "Operand.h"

using namespace calculator;
using std::shared_ptr;
using std::vector;
using std::map;

//// Static Data ////
map<OperatorChar, OperatorMetaData> Operator::operatorMetaData = Operator::createOperatorMap();

//// Static Functions ////

map<OperatorChar, OperatorMetaData> Operator::createOperatorMap() {
    map<OperatorChar, OperatorMetaData> metaMap;
    metaMap[OpAddition] = OperatorMetaData(ArityBinary, AssociativityLeft, 10);
    metaMap[OpSubtraction] = OperatorMetaData(ArityBinary, AssociativityLeft, 10);
    metaMap[OpMultiplication] = OperatorMetaData(ArityBinary, AssociativityLeft, 20);
    metaMap[OpDivision] = OperatorMetaData(ArityBinary, AssociativityLeft, 20);
    metaMap[OpExponent] = OperatorMetaData(ArityBinary, AssociativityRight, 60);

    return metaMap;
}

//// Static Finding Derivatives ////
Differentiable Operator::sumRule(Differentiable &leftOperand,
        Differentiable &rightOperand) {

    auto children = {leftOperand.derivative(), rightOperand.derivative()};
    return Operator(OpAddition, children);
}

Differentiable Operator::differenceRule(Differentiable& leftOperand,
        Differentiable& rightOperand) {

    auto children = {leftOperand.derivative(), rightOperand.derivative()};
    return Operator(OpSubtraction, children);
}

Differentiable Operator::productRule(Differentiable& leftOperand,
        Differentiable& rightOperand) {
    auto leftdx = leftOperand.derivative();
    auto rightdx = rightOperand.derivative(); 

    auto leftOperanddx = Operator(OpMultiplication, {leftOperand, rightdx});
    auto rightOperanddx = Operator(OpMultiplication, {leftdx, rightOperand});

    return Operator(OpAddition, {leftOperanddx, rightOperanddx});
}

Differentiable Operator::quotientRule(Differentiable& numerator,
        Differentiable& denominator) {

    auto numdx = numerator.derivative();
    auto dendx = denominator.derivative();

    //Square the denominator for the derivative's denominator
    auto denominatordx = Operator(OpExponent, {denominator, Operand(2)});

    //Create the two terms for the derivative's numerator
    auto leftdx = Operator(OpMultiplication, {denominator, numdx});
    auto rightdx = Operator(OpMultiplication, {numerator, dendx});

    //Combine into the numerator
    auto numeratordx = Operator(OpSubtraction, {leftdx, rightdx});

    //Return numerator / denominator
    return Operator(OpDivision, {numeratordx, denominatordx});
}


//// Public Methods ////
////// Constructors //////
Operator::Operator(): opChar(OpNone) {}

Operator::Operator(const OperatorChar opChar, const vector<Differentiable> children):
children(children), opChar(opChar), metaData(operatorMetaData[opChar]){

}
////// Operations ///////
Differentiable Operator::derivative() const {
    switch (opChar) {
        case OpAddition:
            break;
        case OpSubtraction:
            break;
        case OpMultiplication:
            break;
        case OpDivision:
            break;
        case OpExponent:
            break;
        default:
            break;
    }

}

