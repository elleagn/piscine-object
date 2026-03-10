#pragma once

#include <string>
#include <map>
#include "Command.hpp"


class ThursdayDiscountCommand: public Command {

    protected:

        ThursdayDiscountCommand();

    public:
        
        ThursdayDiscountCommand(const ThursdayDiscountCommand& copy);
        ThursdayDiscountCommand(std::string date, std::string client);
        virtual ~ThursdayDiscountCommand();

        ThursdayDiscountCommand& operator=(const ThursdayDiscountCommand& assign);

        virtual int get_total_price() const;

};