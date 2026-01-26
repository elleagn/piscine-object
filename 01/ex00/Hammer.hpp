#ifndef HAMMER_HPP
# define HAMMER_HPP

#include "ATool.hpp"

class Hammer : public ATool
{
	public:

		Hammer();
		Hammer(const Hammer &copy);
		~Hammer();

		Hammer & operator=(const Hammer &assign);

		void use();


};

#endif
