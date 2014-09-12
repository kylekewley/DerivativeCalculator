#ifndef DIFFERENTIABLE_H
#define DIFFERENTIABLE_H

#include <memory>

namespace calculator {
    class Differentiable {
        public:
        virtual ~Differentiable() {}

        virtual Differentiable derivative() const;

        private:
    };
}

#endif
