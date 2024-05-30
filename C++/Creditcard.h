#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Bankcard.h"
#include <iostream>
#include <string>

class Creditcard : public Bankcard {
private:
    int cvcNumber, creditLimit, gracePeriod;
    std::string expirationDate;
    float interestRate;
    bool isGranted;

public:
    Creditcard(std::string clientName, std::string issuerBank, std::string bankAccount, int cardId, int balanceAmount, 
               int cvcNumber, int creditLimit, int gracePeriod, std::string expirationDate, float interestRate, bool isGranted)
        : Bankcard(clientName, issuerBank, bankAccount, cardId, balanceAmount), 
          cvcNumber(cvcNumber), creditLimit(creditLimit), gracePeriod(gracePeriod), 
          expirationDate(expirationDate), interestRate(interestRate), isGranted(isGranted) {}

    int getCVCNumber() const {
        return cvcNumber;
    }

    int getCreditLimit() const {
        return creditLimit;
    }

    int getGracePeriod() const {
        return gracePeriod;
    }

    std::string getExpirationDate() const {
        return expirationDate;
    }

    float getInterestRate() const {
        return interestRate;
    }

    bool isGrantedStatus() const {
        return isGranted;
    }

    void setCreditLimit(int newCreditLimit, int newGracePeriod) {
        if (newCreditLimit <= 2.5 * getBalanceAmount()) {
            creditLimit = newCreditLimit;
            gracePeriod = newGracePeriod;
            isGranted = true;
        } else {
            std::cout << "Credit cannot be issued\n";
        }
    }

    void cancelCreditCard() {
        cvcNumber = 0;
        creditLimit = 0;
        gracePeriod = 0;
        isGranted = false;
    }

    void displayCreditDetails() const {
        display();
        if (isGranted) {
            std::cout << "CVC Number: " << getCVCNumber() << std::endl;
            std::cout << "Interest Rate: " << getInterestRate() << std::endl;
            std::cout << "Expiration Date: " << getExpirationDate() << std::endl;
            std::cout << "Credit Limit: " << getCreditLimit() << std::endl;
            std::cout << "Grace Period: " << getGracePeriod() << std::endl;
        }
    }
};

#endif 
