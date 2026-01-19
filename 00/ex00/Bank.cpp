#include "Bank.hpp"

Bank::Bank(): liquidity(0), nextId(0) {

}

Bank::Bank(const Bank& bank): liquidity(bank.liquidity),
nextId(bank.nextId) ,clientAccounts(bank.clientAccounts) {

}

Bank& Bank::operator=(const Bank& bank) {
    this->liquidity = bank.liquidity;
    this->nextId = bank.nextId;
    this->clientAccounts = bank.clientAccounts;
    return(*this);
}

Bank::~Bank() {
    for (std::map<int, Account *>::iterator it = clientAccounts.begin();
    it == clientAccounts.end(); it++) {
        delete it->second;
    }
}

Bank::Account& Bank::operator[](int id) {
    return (*clientAccounts[id]);
}

void Bank::createAccount(int initialDeposit = 0) {

    Account *newAccount;
    try {
        newAccount = new Account;
        newAccount->balance = initialDeposit;

    } catch (std::exception &e) {
        std::cout << "Account creation failed: " << e.what() << std::endl;
        return ;
    }

    clientAccounts[nextId] = newAccount;
    std::cout << "Account successfully created with id " << nextId << std::endl;
    nextId++;

}


void Bank::deleteAccount(int id) {
    delete clientAccounts[id];
    clientAccounts.erase(id);
    std::cout << "Account " << id << "successfully deleted";
}

void Bank::deposit(int accountId, int amount) {
    clientAccounts[accountId]->balance += (amount * 95) / 100;
    liquidity = amount - (amount * 95) / 100;
    std::cout   << "Deposit of " << amount << "in account " << accountId
                << " successful. New balance: "
                << clientAccounts[accountId]->balance << std::endl;
}

void Bank::withdraw(int accountId, int amount) {
    clientAccounts[accountId]->balance -= amount;
    std::cout   << "Withdrawal of " << amount << "from account " << accountId
                << " successful. New balance "
                << clientAccounts[accountId]->balance << std::endl;
}

void Bank::requestLoan(int accountId, int amount){
    clientAccounts[accountId]->balance += amount;
    liquidity -= amount;
    std::cout   << "Bank loaned " << amount << " to account " << accountId
                << ". New balance: " << clientAccounts[accountId]->balance << std::endl;
}

