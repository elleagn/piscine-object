#pragma once

#include <vector>

class Bank {

    public:
        Bank();
        Bank(const Bank& bank);
        Bank& operator=(const Bank& bank);
        virtual ~Bank();


        class   Account;
        void    createAccount(unsigned int initialDeposit);
        void    deposit(unsigned int accountId, unsigned int amount);
        void    withdraw(unsigned int accountId, unsigned int amount);
        void    requireLoan(unsigned int accountId, unsigned int amount);
        void    repayLoan(unsigned int accountId, unsigned int amount);

        Account& operator[](unsigned int id);

    private:
        int liquidity;
        std::vector<Account *> clientAccounts;

};

class Bank::Account {

    public:

        virtual ~Account();

    private:
        Account();
        Account(const Account& Account);
        Account& operator=(const Account& account);


};
