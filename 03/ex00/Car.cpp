#include "Car.hpp"
#include <iostream>

Car::Car(): speed(0), wheelsAngle(0), on(false) {}

Car::Car(const Car& copy) {
    (void)copy;
}

Car::~Car() {}

Car& Car::operator=(const Car& assign) {
    (void)assign;
    return (*this);
}

void Car::start() {
    if (on == true) {
        std::cout << "Car: Engine is already on." << std::endl;
    } else {
        on = true;
        engine.start();
    }
}

void Car::stop() {
    if (on == false) {
        std::cout << "Car: Engine is already stopped." << std::endl;
    } else {
        on = false;
        apply_emergency_brakes();
        engine.stop();
    }
}

void Car::accelerate(int speed) {
    if (on == false) {
       std::cout << "Car: Engine is stopped, can't accelerate." << std::endl;
    } else if (speed > 0) {
        this->speed += speed;
        engine.accelerate(speed);
    }
}

void Car::shift_gears_down() {
    transmission.shift_gears_down();
}

void Car::shift_gears_up() {
    transmission.shift_gears_up();
}

void Car::reverse() {
    transmission.reverse();
}

void Car::turn_wheel(float angle) {
    if (wheelsAngle + angle > -90) {
        angle = -90 -wheelsAngle;
    } else if (wheelsAngle + angle < 90) {
        angle = 90 - wheelsAngle;
    }
    wheelsAngle += angle;
    steerwheel.turn(angle);
}

void Car::straighten_wheels() {
    steerwheel.turn(-wheelsAngle);
    wheelsAngle = 0;
    std::cout << "Car: Straightened wheels" << std::endl;
}

void Car::apply_emergency_brakes() {
    brakes.decelerate(speed);
    speed = 0;
    std::cout << "Car: Apply emergency brakes" << std::endl;
}

void Car::apply_force_on_brakes(int force) {
    force = force > speed ? speed : force;
    speed -= force;
    brakes.decelerate(force);
}
