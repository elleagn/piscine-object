#include "Worker.hpp"
#include "Colors.hpp"
#include <iostream>
#include "Shovel.hpp"

// POSITION

Position::Position(): x(0), y(0) {
    std::cout << RED << "Position: Created." << RESET << std::endl;
}

Position::~Position() {
    std::cout << RED << "Position: Destroyed." << RESET << std::endl;
}

// Statistic

Statistic::Statistic(): level(0), exp(0) {
    std::cout << GREEN << "Statistic: Created." << RESET << std::endl;
}

Statistic::~Statistic() {
    std::cout << GREEN << "Statistic: Destroyed." << RESET << std::endl;
}


// WORKER

Worker::Worker() {}

Worker::Worker(std::string name) : name(name), shovel(NULL) {
    std::cout   << YELLOW << "Worker " << name << ": Created." << RESET
                << std::endl;
}

Worker::Worker(const Worker& src): coordonnee(src.coordonnee), stat(src.stat),
name(src.name), shovel(NULL) {};

Worker& Worker::operator=(const Worker& src) {
    name = src.name;
    coordonnee = src.coordonnee;
    stat = src.stat;
    shovel = NULL;
    return (*this);
}

Worker::~Worker() {
    std::cout   << YELLOW << "Worker " << name << ": Destroyed." << RESET
                << std::endl;
}

void Worker::takeShovel(Shovel*tool) {
    shovel = tool;
    std::cout   << YELLOW << "Worker " << name << ": Took a shovel." << RESET
                << std::endl;
}

void Worker::dropShovel() {
    shovel = NULL;
    std::cout   << YELLOW << "Worker " << name << ": Dropped shovel." << RESET
                << std::endl;
}
