#pragma once

#include <map>
#include <iostream>

class Bank {

    public:
        Bank();
        Bank(const Bank& bank);
        Bank& operator=(const Bank& bank);
        virtual ~Bank();

        int getLiquidity() const;
        void printAccounts() const;

        class   Account;
        Account& operator[](int id);
        int     createAccount(int initialDeposit = 0);
        void    deleteAccount(int id);
        void    deposit(int accountId, int amount);
        void    withdraw(int accountId, int amount);
        void    requestLoan(int accountId, int amount);

        class AccountDoesNotExist: public std::exception {
            const char *what() const throw();
        };

        class InsufficientBalance: public std::exception {
            const char *what() const throw();
        };

        class InsufficientFunds: public std::exception {
            const char *what() const throw();
        };

    private:
        int liquidity;
        int nextId;
        std::map<int, Account *> clientAccounts;

};

class Bank::Account {

    friend class Bank;

    public:

        virtual ~Account();
        const int& getId() const;
        const int& getBalance() const;

    private:

        Account();
        Account(const Account& account);
        Account& operator=(const Account& account);

        int balance;
        int id;

};

std::ostream& operator<<(std::ostream& out, const Bank::Account& account);
std::ostream& operator<<(std::ostream& out, const Bank& bank);
