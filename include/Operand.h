#ifndef OPERAND_H
#define OPERAND_H

#include "Differentiable.h"

namespace calculator {
    class Operand : public Differentiable {
        public:
        Operand(int constant);

        virtual Differentiable derivative() const;

        private:

    };
}
#endif
