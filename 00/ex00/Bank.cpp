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
    it != clientAccounts.end(); it++) {
        delete it->second;
    }
}

int Bank::getLiquidity() const {
    return(liquidity);
}

void Bank::printAccounts() const {\

    for (std::map<int, Account *>::const_iterator it = clientAccounts.begin();
        it != clientAccounts.end(); it++) {
            std::cout << *(it->second);
    }
}

Bank::Account& Bank::operator[](int id) {
    std::map<int, Account *>::iterator it = clientAccounts.find(id);
    if (it == clientAccounts.end()) {
        throw AccountDoesNotExist();
    }
    return (*clientAccounts[id]);
}

int Bank::createAccount(int initialDeposit) {

    Account *newAccount;

    newAccount = new Account;
    newAccount->balance = initialDeposit;
    newAccount->id = nextId;

    clientAccounts[nextId] = newAccount;
    std::cout << "Account successfully created with id " << nextId << std::endl;
    nextId++;
    return (nextId - 1);

}


void Bank::deleteAccount(int id) {
    delete clientAccounts[id];
    clientAccounts.erase(id);
    std::cout << "Account " << id << "successfully deleted";
}

void Bank::deposit(int accountId, int amount) {
    std::map<int, Account *>::iterator it = clientAccounts.find(accountId);
    if (it == clientAccounts.end()) {
        throw AccountDoesNotExist();
    }
    clientAccounts[accountId]->balance += (amount * 95) / 100;
    liquidity += amount - ((amount * 95) / 100);
    std::cout   << "Deposit of " << amount << " in account " << accountId
                << " successful. New balance: "
                << clientAccounts[accountId]->balance << std::endl;
}

void Bank::withdraw(int accountId, int amount) {
    std::map<int, Account *>::iterator it = clientAccounts.find(accountId);
    if (it == clientAccounts.end()) {
        throw AccountDoesNotExist();
    }
    if (clientAccounts[accountId]->balance < amount) {
        throw InsufficientBalance();
    }
    clientAccounts[accountId]->balance -= amount;
    std::cout   << "Withdrawal of " << amount << "from account " << accountId
                << " successful. New balance "
                << clientAccounts[accountId]->balance << std::endl;
}

void Bank::requestLoan(int accountId, int amount){
    std::map<int, Account *>::iterator it = clientAccounts.find(accountId);
    if (it == clientAccounts.end()) {
        throw AccountDoesNotExist();
    }
    if (liquidity < amount) {
        throw InsufficientFunds();
    }
    liquidity -= amount;
    clientAccounts[accountId]->balance += amount;
    std::cout   << "Bank loaned " << amount << " to account " << accountId
                << ". New balance: " << clientAccounts[accountId]->balance << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bank& bank) {
    out << "Bank informations : " << std::endl;
    out << "Liquidity : " << bank.getLiquidity() << std::endl;
	bank.printAccounts();
	return (out);
}

const char *Bank::AccountDoesNotExist::what() const throw() {
    return ("Exception: The requested account does not exist.");
}

const char *Bank::InsufficientBalance::what() const throw() {
    return ("Exception: This account's balance is insufficient for this operation.");
}

const char *Bank::InsufficientFunds::what() const throw() {
    return("Exception: The bank doesn't have the funds for this operation.");
}
