#include "Command.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>


bool isLeapYear(int year) {

    // year not divisible by 4
    if (year % 4)
        return (false);

    // year divisible by 4 but not by 100
    if (year % 100)
        return (true);

    // year divisible by 100 but not by 400
    if (year % 400)
        return (false);

    return (true);

}

bool checkDateFormat(std::string date) {

    bool res = true;

    if (date.size() != 10)
        res = false;
    for (int i = 0; i < 10 && res; i++) {
        if ((i == 4 || i == 7) && date[i] != '-')
            res = false;
        if (i != 4 && i != 7 && !isdigit(date[i]))
            res = false;
    }
    if (!res) {
        std::cout << "Error: Invalid date format." << std::endl;
        return (false);
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
        res = false;
    if (res && day == 31 && ((month % 2 == 0 && month <= 6)
            || (month % 2 == 1 && month > 7)))
        res = false;
    if (res && month == 2 && (day > 29 || (day == 29 && !isLeapYear(year) )))
        res = false;
    if (!res) {
        std::cout << "Error: date doesn't exist." << std::endl;
        return (false);
    }


    return (res);

}

std::map<std::string, int> Command::prices;
int Command::last_id = 0;

Command::Command() {};

Command::Command(const Command& copy): id(copy.id), date(copy.date), 
    client(copy.client), basket(copy.basket) {}

Command::Command(std::string date, std::string client): id(last_id), date(date), 
    client(client) {
        last_id++;
        if (!checkDateFormat(date)) {
            throw std::invalid_argument("Wrong date format.") ;
        }
    }

Command::~Command() {}


Command& Command::operator=(const Command& assign) {
    id = assign.id;
    date = assign.date;
    client = assign.client;
    basket = assign.basket;
    return (*this);
}

void Command::add_article(std::string article, int quantity) {
    
    if (prices.find(article) == prices.end()) {
        std::cout << "Article " << article << " does not exist." << std::endl;
    } else {
        basket[article] += quantity;
    }
};

int Command::get_total_price() const {

    int total = 0;

    for (std::map<std::string, int>::const_iterator it = basket.begin(); it != basket.end(); it++) {
        total += it->second * prices[it->first];
    }
    return (total);
}