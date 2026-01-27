#include "ATool.hpp"
#include "Colors.hpp"
#include <iostream>
#include "Worker.hpp"

ATool::ATool(): numberOfUses(0), user(NULL) {
    std::cout << BLUE << "Tool: Created." << RESET << std::endl;
}

ATool::ATool(const ATool& src): numberOfUses(src.numberOfUses) {}

ATool& ATool::operator=(const ATool& src) {
    numberOfUses = src.numberOfUses;
    return (*this);
}

ATool::~ATool() {
    if (user!= NULL){
        user->dropTool(this);
    }
    std::cout << BLUE << "Tool: Destroyed." << RESET << std::endl;
}

void ATool::beTaken(Worker* worker) {
    if (user) {
        user->dropTool(this);
    }
    user = worker;
    std::cout   << BLUE << "Tool: Taken by worker " << worker->getName()
                << RESET << std::endl;
}

void ATool::getAway() {
    if (user != NULL) {
        std::cout   << BLUE << "Tool: Got away from " << user->getName()
                    << RESET << std::endl;
    }
    user = NULL;
}
