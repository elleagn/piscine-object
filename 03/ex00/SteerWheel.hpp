#pragma once

class SteerWheel {
    public:
        SteerWheel();
        SteerWheel(const SteerWheel& copy);
        ~SteerWheel();

        SteerWheel& operator=(const SteerWheel& assign);

        void turn(float angle);
};
