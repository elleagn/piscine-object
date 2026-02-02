#include "Transmission.hpp"

Transmission::Transmission(): currentGear(0) {}

Transmission::Transmission(const Transmission& copy): currentGear(copy.currentGear) {
    (void)copy;
}

Transmission::~Transmission() {}

Transmission& Transmission::operator=(const Transmission& assign) {
    currentGear = assign.currentGear;
    return (*this);
}
