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


    vector<Differentiable> children;
    //(leftOperand.derivative(), rightOperand.derivative());

    return Operator(OpAddition, children);
}

Differentiable Operator::differenceRule(Differentiable& leftOperand,
        Differentiable& rightOperand) {
}

Differentiable Operator::productRule(Differentiable& leftOperand,
        Differentiable& rightOperand) {
}

Differentiable Operator::quotientRule(Differentiable& numerator,
        Differentiable& denominator) {
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

