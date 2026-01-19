#include "Bank.hpp"

int main(void) {
    Bank bank;
    int  id;

    id = bank.createAccount();
    bank.deposit(id, 100);
    bank.withdraw(id,20);
    bank.requestLoan(id, 3);

}

