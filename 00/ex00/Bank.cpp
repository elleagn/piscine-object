#include "Bank.hpp"

Bank::Bank(): liquidity(0) {

}

Bank::Bank(const Bank& bank):
liquidity(bank.liquidity), clientAccounts(bank.clientAccounts) {

}

Bank& Bank::operator=(const Bank& bank) {
    this->liquidity = bank.liquidity;
    this->clientAccounts = bank.clientAccounts;
    return(*this);
}
