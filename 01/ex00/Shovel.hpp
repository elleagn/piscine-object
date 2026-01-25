#ifndef SHOVEL_HPP
# define SHOVEL_HPP

#include "ATool.hpp"

class Shovel : public ATool
{
	public:

		Shovel();
		Shovel(const Shovel &copy);
		~Shovel();

		Shovel & operator=(const Shovel &assign);

		void use();


};

#endif
