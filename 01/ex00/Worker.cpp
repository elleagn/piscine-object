#include "Worker.hpp"
#include "Colors.hpp"
#include <iostream>
#include "ATool.hpp"
#include "Workshop.hpp"

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

Worker::Worker(std::string name) : name(name) {
    std::cout   << YELLOW << "Worker " << name << ": Created." << RESET
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
    std::vector<ATool *>::iterator it = tools.begin();
    while (it != tools.end()) {
        (*it)->getAway();
        it++;
    }
    std::vector<Workshop *>::iterator shopIt = shops.begin();
    while (shopIt != shops.end()) {
        (*shopIt)->releaseWorker(this);
        shopIt++;
    }
    std::cout   << YELLOW << "Worker " << name << ": Destroyed." << RESET
                << std::endl;
}

void Worker::takeTool(ATool*tool) {
    tools.push_back(tool);
    tool->beTaken(this);
    std::cout   << YELLOW << "Worker " << name << ": Took a tool." << RESET
                << std::endl;
}

void Worker::dropTool(ATool* tool) {
    std::vector<ATool *>::iterator it = tools.begin();
    while (it != tools.end()) {
        if (*it == tool) {
            tools.erase(it);
            tool->getAway();
            std::cout   << YELLOW << "Worker " << name << ": Dropped tool." << RESET
                        << std::endl;
            return ;
        }
        it++;
    }
}

const std::string& Worker::getName() const {
    return name;
}

bool Worker::hasTool(ATool* tool) const {
    std::vector<ATool *>::const_iterator it = tools.begin();
    while (it != tools.end()) {
        if (*it == tool) {
            std::cout   << YELLOW << "Worker " << name << ": Has tool." << RESET
                        << std::endl;
            return true;
        }
        it++;
    }
    std::cout   << YELLOW << "Worker " << name << ": Doesn't have tool."
                << RESET << std::endl;
    return false;
}

void Worker::registerToWorkshops(std::vector<Workshop *> wshops) {
    shops.insert(shops.end(), wshops.begin(), wshops.end());
    std::cout << YELLOW << "Worker " << name << ": Registered to workshops." << RESET << std::endl;
}

void Worker::registerToWorkshops(Workshop* shop) {
    shops.push_back(shop);
    std::cout << YELLOW << "Worker " << name << ": Registered to workshop." << RESET << std::endl;
}

void Worker::leaveWorkshop(Workshop* shop) {
    std::vector<Workshop *>::iterator shopIt = shops.begin();
    while (shopIt != shops.end()) {
        if (*shopIt == shop) {
            shops.erase(shopIt);
        }
        shopIt++;
    }
    std::cout << YELLOW << "Worker " << name << ": Left workshop."<< RESET << std::endl;
}

void Worker::work() const {
    std::cout << YELLOW << "Worker " << name << ": Working..." << std::endl;
}
