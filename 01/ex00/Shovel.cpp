#include "Shovel.hpp"
#include "Worker.hpp"
#include <iostream>
#include "Colors.hpp"

// Constructors
Shovel::Shovel()
{
	std::cout << MAGENTA << "Shovel: Created" << RESET << std::endl;
}

Shovel::Shovel(const Shovel &copy)
{
	numberOfUses = copy.numberOfUses;
}


// Destructor
Shovel::~Shovel()
{
	if (user!= NULL){
        user->dropTool(this);
    }
	std::cout << MAGENTA << "Shovel: Destroyed." << RESET << std::endl;
}


// Operators
Shovel & Shovel::operator=(const Shovel &assign)
{
	numberOfUses = assign.numberOfUses;
	return *this;
}

void Shovel::use() {
	numberOfUses++;
	std::cout 	<< MAGENTA << "Shovel: Digging... (use " << numberOfUses <<")"
				<< RESET << std::endl;
}
