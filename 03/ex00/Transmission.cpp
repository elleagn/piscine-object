#include "Transmission.hpp"
#include <iostream>

Transmission::Transmission(): currentGear(0) {}

Transmission::Transmission(const Transmission& copy): currentGear(copy.currentGear) {
    (void)copy;
}

Transmission::~Transmission() {}

Transmission& Transmission::operator=(const Transmission& assign) {
    currentGear = assign.currentGear;
    return (*this);
}

void Transmission::shift_gears_down() {
    if (currentGear == 6) {
        std::cout << "Transmission: already at max gear" << std::endl;
    } else {
        currentGear++;
        std::cout << "Transmission: Gear shifted up to" << currentGear << std::endl;
    }
}

void Transmission::shift_gears_up() {
    if (currentGear == -1) {
        std::cout << "Transmission: Already in reverse gear." << std::endl;
    } else if (currentGear == 0) {
        std::cout << "Transmission: already in neutral gear" << std::endl;
    } else {
        currentGear--;
        std::cout << "Transmission: Gear shifted down to" << currentGear << std::endl;
    }
}

void Transmission::reverse() {
    currentGear = -1;
    std::cout << "Transmission: Put transmission in reverse gear." << std::endl;
}
