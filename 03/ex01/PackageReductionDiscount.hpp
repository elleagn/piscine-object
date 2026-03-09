#pragma once

#include <string>
#include <map>
#include "Command.hpp"


class PackageReductionDiscountCommand: public Command {

    protected:

        PackageReductionDiscountCommand();

    public:
        
        PackageReductionDiscountCommand(const PackageReductionDiscountCommand& copy);
        PackageReductionDiscountCommand(std::string date, std::string client);
        virtual ~PackageReductionDiscountCommand();

        PackageReductionDiscountCommand& operator=(const PackageReductionDiscountCommand& assign);

        virtual int get_total_price() const;

};
