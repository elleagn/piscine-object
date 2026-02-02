#pragma once

#include  "Brake.hpp"
#include "Engine.hpp"
#include "SteerWheel.hpp"
#include "Transmission.hpp"

class Car {

    private:
        Brake brakes;
        SteerWheel steerwheel;
        Transmission transmission;
        Engine engine;

        int speed;
        int wheelsAngle;
        bool on;

    public:
        Car();
        Car(const Car& copy);
        ~Car();

        Car& operator=(const Car& assign);

        void start();
        void stop();
        void accelerate(int speed);
        void shift_gears_up();
        void shift_gears_down();
        void reverse();
        void turn_wheel(float angle);
        void straighten_wheels();
        void apply_force_on_brakes(int force);
        void apply_emergency_brakes();
};
