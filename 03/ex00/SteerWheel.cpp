#include "SteerWheel.hpp"

SteerWheel::SteerWheel() {}

SteerWheel::SteerWheel(const SteerWheel& copy) {
    (void)copy;
}

SteerWheel::~SteerWheel() {}

SteerWheel& SteerWheel::operator=(const SteerWheel& assign) {
    (void)assign;
    return (*this);
}
