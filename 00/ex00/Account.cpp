#include "Bank.hpp"

Bank::Account::Account() {}

Bank::Account::Account(const Account& account): balance(account.balance){

}

Bank::Account& Bank::Account::operator=(const Account& account) {
    balance = account.balance;
    return (*this);
}

Bank::Account::~Account() {};

const int& Bank::Account::getId() const {
    return (id);
}

const int& Bank::Account::getBalance() const {
    return (balance);
}

std::ostream& operator<<(std::ostream& out, const Bank::Account& account) {
    out << "[" << account.getId() << "] - [" << account.getBalance() << "]"
        << std::endl;

    return (out);
}
