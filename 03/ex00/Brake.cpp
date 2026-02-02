#include "Brake.hpp"

Brake::Brake() {}

Brake::Brake(const Brake& copy) {
    (void)copy;
}

Brake::~Brake() {}

Brake& Brake::operator=(const Brake& assign) {
    (void)assign;
    return (*this);
}

