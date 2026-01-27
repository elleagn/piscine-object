#include "Hammer.hpp"
#include "Worker.hpp"
#include <iostream>
#include "Colors.hpp"

// Constructors
Hammer::Hammer()
{
	std::cout << CYAN << "Hammer: Created" << RESET << std::endl;
}

Hammer::Hammer(const Hammer &copy)
{
	numberOfUses = copy.numberOfUses;
}


// Destructor
Hammer::~Hammer()
{
	if (user!= NULL){
        user->dropTool(this);
    }
	std::cout << CYAN << "Hammer: Destroyed." << RESET << std::endl;
}


// Operators
Hammer & Hammer::operator=(const Hammer &assign)
{
	numberOfUses = assign.numberOfUses;
	return *this;
}

void Hammer::use() {
	numberOfUses++;
	std::cout 	<< CYAN << "Hammer: Hammering... (use " << numberOfUses <<")"
				<< RESET << std::endl;
}
