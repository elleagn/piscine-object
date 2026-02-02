#include "Car.hpp"

Car::Car(): speed(0), wheelsAngle(0) {}

Car::Car(const Car& copy) {
    (void)copy;
}

Car::~Car() {}

Car& Car::operator=(const Car& assign) {
    (void)assign;
    return (*this);
}
