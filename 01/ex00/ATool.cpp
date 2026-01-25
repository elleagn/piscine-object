#include "ATool.hpp"
#include "Colors.hpp"
#include <iostream>
#include "Worker.hpp"

ATool::ATool(): numberOfUses(0) {
    std::cout << BLUE << "Tool: Created." << RESET << std::endl;
}

ATool::ATool(const ATool& src): numberOfUses(src.numberOfUses) {}

ATool& ATool::operator=(const ATool& src) {
    numberOfUses = src.numberOfUses;
    return (*this);
}

ATool::~ATool() {
    std::cout << BLUE << "Tool: Destroyed." << RESET << std::endl;
}
