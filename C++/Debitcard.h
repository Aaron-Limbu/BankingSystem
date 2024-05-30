#ifndef DEBITCARD_H
#define DEBITCARD_H

#include "Bankcard.h"
#include <iostream>
#include <string>

class Debitcard : public Bankcard {
private:
    int pinNumber, withdrawalAmount;
    std::string dateOfWithdrawal;
    bool hasWithdrawn;

public:
    Debitcard(std::string clientName, std::string issuerBank, std::string bankAccount, int cardId, int balanceAmount, 
              int pinNumber, int withdrawalAmount)
        : Bankcard(clientName, issuerBank, bankAccount, cardId, balanceAmount), 
          pinNumber(pinNumber), withdrawalAmount(withdrawalAmount), hasWithdrawn(false) {}

    int getPinNumber() const {
        return pinNumber;
    }

    int getWithdrawalAmount() const {
        return withdrawalAmount;
    }

    std::string getDateOfWithdrawal() const {
        return dateOfWithdrawal;
    }

    bool hasWithdrawnStatus() const {
        return hasWithdrawn;
    }

    void setWithdrawalAmount(int amount) {
        withdrawalAmount = amount;
    }

    void withdraw(int pin, int amount, const std::string &date) {
        if (getPinNumber() == pin) {
            std::cout << "You have been granted access.\n";
            if (amount > getBalanceAmount()) {
                std::cout << "You cannot withdraw an amount above your balance.\n";
            } else {
                setBalanceAmount(getBalanceAmount() - amount);
                dateOfWithdrawal = date;
                hasWithdrawn = true;
                std::cout << amount << " has been deducted from your balance amount.\n";
            }
        } else {
            std::cout << "Incorrect PIN.\n";
        }
    }

    void displayDetails() const {
        display();
        if (hasWithdrawn) {
            std::cout << "PIN Number: " << getPinNumber() << std::endl;
            std::cout << "Withdrawal Amount: " << getWithdrawalAmount() << std::endl;
            std::cout << "Date of Withdrawal: " << getDateOfWithdrawal() << std::endl;
        } else {
            std::cout << "Current balance amount is " << getBalanceAmount() << std::endl;
        }
    }
};

#endif