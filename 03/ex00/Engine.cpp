#include "Engine.hpp"

Engine::Engine(): on(false) {}

Engine::Engine(const Engine& copy): on(copy.on) {
    (void)copy;
}

Engine::~Engine() {}

Engine& Engine::operator=(const Engine& assign) {
    on = assign.on;
    return (*this);
}
