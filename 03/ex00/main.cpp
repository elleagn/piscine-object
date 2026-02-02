#include "Car.hpp"
#include <iostream>

int main() {
    Car testCar;

    std::cout << "Start" << std::endl;
    testCar.start();

    std::cout << "\nGear up\n";
    testCar.shift_gears_up();

    std::cout << "\nAccelerate\n";
    testCar.accelerate(90);

    std::cout << "\nGear down\n";
    testCar.shift_gears_down();

    std::cout << "\nReverse\n";
    testCar.reverse();

    std::cout << "\nTurn wheels\n";
    testCar.turn_wheel(30);

    std::cout << "\nStraighten wheels\n";
    testCar.straighten_wheels();

    std::cout << "\nApply force on brakes\n";
    testCar.apply_force_on_brakes(10);

    std::cout << "\nApply emergency brakes\n";
    testCar.apply_emergency_brakes();

    std::cout << "\nStop\n";
    testCar.stop();
}
