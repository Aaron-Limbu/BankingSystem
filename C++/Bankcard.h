#ifndef BANKCARD_H
#define BANKCARD_H

#include <string>
#include <iostream>

class Bankcard {
private:
    std::string clientName, issuerBank, bankAccount;
    int cardId, balanceAmount;

public:
    Bankcard(std::string clientName, std::string issuerBank, std::string bankAccount, int cardId, int balanceAmount)
        : clientName(clientName), issuerBank(issuerBank), bankAccount(bankAccount), cardId(cardId), balanceAmount(balanceAmount) {}

    std::string getClientName() const {
        return clientName;
    }

    std::string getIssuerBank() const {
        return issuerBank;
    }

    std::string getBankAccount() const {
        return bankAccount;
    }

    int getCardId() const {
        return cardId;
    }

    int getBalanceAmount() const {
        return balanceAmount;
    }

    void setBalanceAmount(int amount) {
        balanceAmount = amount;
    }

    void setClientName(const std::string &name) {
        clientName = name;
    }

    void display() const {
        std::cout << "The card ID is " << getCardId() << std::endl;
        if (clientName.empty()) {
            std::cout << "There is no client name stored\n";
        } else {
            std::cout << "The client name is " << getClientName() << std::endl;
        }
        std::cout << "Issuer bank is " << getIssuerBank() << std::endl;
        std::cout << "The bank account is " << getBankAccount() << std::endl;
        std::cout << "Balance amount is " << getBalanceAmount() << std::endl;
    }
};

#endif 
