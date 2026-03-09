#include "PackageReductionDiscount.hpp"

PackageReductionDiscountCommand::PackageReductionDiscountCommand() : Command() {}

PackageReductionDiscountCommand::PackageReductionDiscountCommand(const PackageReductionDiscountCommand& copy): Command(copy) {}

PackageReductionDiscountCommand::PackageReductionDiscountCommand(std::string date, std::string client): Command(date, client) {}

PackageReductionDiscountCommand::~PackageReductionDiscountCommand() {}

PackageReductionDiscountCommand& PackageReductionDiscountCommand::operator=(const PackageReductionDiscountCommand& assign) {
    this->Command::operator=(assign);
    return (*this);
}


int PackageReductionDiscountCommand::get_total_price() const {
    int total = this->Command::get_total_price();
    if (total >= 150) {
        total -= 10;
    }

    return (total);
}