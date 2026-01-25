#include "ATool.hpp"
#include "Colors.hpp"
#include <iostream>

ATool::ATool(): numberOfUses(0) {
    std::cout << BLUE << "Tool has been created." << RESET << std::endl;
}

ATool::ATool(const ATool& src): numberOfUses(src.numberOfUses) {}

ATool& ATool::operator=(const ATool& src) {
    numberOfUses = src.numberOfUses;
    return (*this);
}

ATool::~ATool() {
    std::cout << BLUE << "Tool has been destroyed." << RESET << std::endl;
}
