#pragma once

class Transmission {

    private:
        int currentGear;

    public:
        Transmission();
        Transmission(const Transmission& copy);
        ~Transmission();

        Transmission& operator=(const Transmission& assign);

        void shift_gears_up();
        void shift_gears_down();
        void reverse();
};
