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
        void    createAccount(int initialDeposit);
        void    deleteAccount(int id);
        void    deposit(int accountId, int amount);
        void    withdraw(int accountId, int amount);
        void    requestLoan(int accountId, int amount);



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
