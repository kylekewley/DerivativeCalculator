#ifndef DIFFERENTIABLE_H
#define DIFFERENTIABLE_H

#include <memory>
#include <iostream>

namespace calculator {
    class Differentiable {
        public:
        virtual ~Differentiable() {}

        virtual Differentiable derivative() const {
            std::cerr << "Error: Subclasses should override the derivative method in Differentiable" << std::endl;
            return Differentiable();
        };

        private:
    };
}

#endif
