#include "Worker.hpp"
#include "Colors.hpp"
#include <iostream>

// POSITION

Position::Position(): x(0), y(0) {
    std::cout << RED << "Position has been created." << RESET << std::endl;
}

Position::~Position() {
    std::cout << RED << "Position has been destroyed." << RESET << std::endl;
}

// Statistic

Statistic::Statistic(): level(0), exp(0) {
    std::cout << GREEN << "Statistic has been created." << RESET << std::endl;
}

Statistic::~Statistic() {
    std::cout << GREEN << "Statistic has been destroyed." << RESET << std::endl;
}


// WORKER

Worker::Worker() {}

Worker::Worker(std::string name) : name(name) {
    std::cout   << YELLOW << "Worker " << name << " has been created." << RESET
                << std::endl;
}

Worker::Worker(const Worker& src): coordonnee(src.coordonnee), stat(src.stat),
name(src.name) {};

Worker& Worker::operator=(const Worker& src) {
    name = src.name;
    coordonnee = src.coordonnee;
    stat = src.stat;
    return (*this);
}

Worker::~Worker() {
    std::cout   << YELLOW << "Worker " << name << " has been destroyed." << RESET
                << std::endl;
}
