#include "SteerWheel.hpp"
#include <iostream>

SteerWheel::SteerWheel() {}

SteerWheel::SteerWheel(const SteerWheel& copy) {
    (void)copy;
}

SteerWheel::~SteerWheel() {}

SteerWheel& SteerWheel::operator=(const SteerWheel& assign) {
    (void)assign;
    return (*this);
}

void SteerWheel::turn(float p_angle) {
    std::cout << "SteerWheel: Turned by " << p_angle << " degrees" << std::endl;
}
