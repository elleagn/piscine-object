#include "ThursdayDiscount.hpp"
#include <cstdlib>

ThursdayDiscountCommand::ThursdayDiscountCommand() : Command() {}

ThursdayDiscountCommand::ThursdayDiscountCommand(const ThursdayDiscountCommand& copy): Command(copy) {}

ThursdayDiscountCommand::ThursdayDiscountCommand(std::string date, std::string client): Command(date, client) {}

ThursdayDiscountCommand::~ThursdayDiscountCommand() {}

ThursdayDiscountCommand& ThursdayDiscountCommand::operator=(const ThursdayDiscountCommand& assign) {
    this->Command::operator=(assign);
    return (*this);
}

int getDayofWeek(std::string date) {
    int year = atoi(date.substr(0, 4).c_str());

    int month = atoi(date.substr(5, 2).c_str());
    if (month <= 2) {
        // February is put at the end of the year so it simplifies leap year calculation
        month += 12;
        year -= 1;
    } 

    int yearOfCentury = year % 100;
    int century = year - yearOfCentury; // zero based ie 1990 -> century 19 and not 20

    int dayOfMonth = atoi(date.substr(8, 2).c_str());

    // Zeller's congruence
    int dayOfWeek = (dayOfMonth + (13 * (month + 1)) / 5 + yearOfCentury + yearOfCentury / 4 + century / 4 + 5 * century) % 7;

    return (dayOfWeek);
}

int ThursdayDiscountCommand::get_total_price() const {
    int total = this->Command::get_total_price();
    
    if (getDayofWeek(date) == 5) {
        total = static_cast<int>((float)total * 0.9);
    }
    return (total);
}