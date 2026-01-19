#include "Bank.hpp"

Bank::Account::Account() {}

Bank::Account::Account(const Account& account): balance(account.balance){

}

Bank::Account& Bank::Account::operator=(const Account& account) {
    balance = account.balance;
    return (*this);
}

Bank::Account::~Account() {};
