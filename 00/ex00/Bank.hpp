#pragma once

#include <map>
#include <iostream>

class Bank {

    public:
        Bank();
        Bank(const Bank& bank);
        Bank& operator=(const Bank& bank);
        virtual ~Bank();


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

    private:

        Account();
        Account(const Account& account);
        Account& operator=(const Account& account);

        int balance;

};
