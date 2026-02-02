#include "Engine.hpp"
#include <iostream>

Engine::Engine() {}

Engine::Engine(const Engine& copy) {
    (void)copy;
}

Engine::~Engine() {}

Engine& Engine::operator=(const Engine& assign) {
    (void)assign;
    return (*this);
}

void Engine::start() {
    std::cout << "Engine: Engine started." << std::endl;
}

void Engine::stop() {
    std::cout << "Engine: Engine stopped." << std::endl;
}

void Engine::accelerate(int speed) {
    std::cout << "Engine: Accelerated by " << speed << "km/h." << std::endl;
}
