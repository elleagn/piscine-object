#include "Brake.hpp"
#include <iostream>

Brake::Brake() {}

Brake::Brake(const Brake& copy) {
    (void)copy;
}

Brake::~Brake() {}

Brake& Brake::operator=(const Brake& assign) {
    (void)assign;
    return (*this);
}

void Brake::decelerate(int speed) {
    std::cout << "Brake: Used brakes and decelerated by " << speed << "km/h." << std::endl;
}
