#include "Engine.hpp"
#include <iostream>

Engine::Engine(): on(false) {}

Engine::Engine(const Engine& copy): on(copy.on) {
    (void)copy;
}

Engine::~Engine() {}

Engine& Engine::operator=(const Engine& assign) {
    on = assign.on;
    return (*this);
}

void Engine::start() {
    if (on == true) {
        std::cout << "Engine: Engine is already on." << std::endl;
    } else {
        on = true;
        std::cout << "Engine: Engine started." << std::endl;
    }
}

void Engine::stop() {
    if (on == false) {
        std::cout << "Engine: Engine is already off." << std::endl;
    } else {
        on = false;
        std::cout << "Engine: Engine stopped." << std::endl;
    }
}

void Engine::accelerate(int speed) {
    std::cout << "Engine: Accelerated by " << speed << "km/h." << std::endl;
}
