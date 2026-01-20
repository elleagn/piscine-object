#include "Bank.hpp"

int main(void) {
    Bank bank;
    int  id;

    id = bank.createAccount();
    bank.deposit(id, 100);
    bank.withdraw(id,20);
    bank.requestLoan(id, 3);
    try {
        bank.requestLoan(id, 10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        bank.withdraw(id, 300);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << bank;
    id = bank.createAccount();
    bank.deposit(id, 4000);
    id = bank.createAccount();
    bank.deposit(id, 30);
    id = bank.createAccount();
    bank.deposit(id, 465);
    std::cout << bank;
    try {
        bank.requestLoan(100, 10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        bank.withdraw(110, 300);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}

