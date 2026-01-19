#include "Bank.hpp"

Bank::Account::Account() {}

Bank::Account::Account(const Account& account) {
    (void)account;
}

Bank::Account& Bank::Account::operator=(const Account& account) {
    (void)account;
    return (*this);
}

Bank::Account::~Account() {};
