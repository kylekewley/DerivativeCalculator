#ifndef OPERAND_H
#define OPERAND_H

#include "Differentiable.h"

namespace calculator {
    class Operand : public Differentiable {
        public:
        virtual std::shared_ptr<Differentiable> derivative() const;

        private:

    };
}
#endif
