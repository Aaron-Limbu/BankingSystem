#include "Bankcard.h"
#include "Debitcard.h"
#include "Creditcard.h"
#include <iostream>

int main(int argc, char *argv[]) {
    int choice;
    do{
        std::cout << "Choose an option: \n";
    std::cout << "1. Use Bankcard\n2. Use Debitcard\n3. Use Creditcard\n4. exit\nEnter your choice: ";
    std::cin >> choice;

    switch(choice) {
        case 1: {
            Bankcard bnkcard("John", "ABC Bank", "123456789", 101, 1000);
            bnkcard.display();
            break;
        }
        case 2: {
            Debitcard debitCard("John", "ABC Bank", "123456789", 101, 1000, 1234, 500);
            debitCard.displayDetails();
            debitCard.withdraw(1234, 300, "2023-05-30");
            debitCard.displayDetails();
            break;
        }
        case 3: {
            Creditcard creditCard("John", "ABC Bank", "123456789", 101, 1000, 567, 1500, 30, "2026-12-31", 1.5f, true);
            creditCard.displayCreditDetails();
            creditCard.setCreditLimit(1000, 45);
            creditCard.displayCreditDetails();
            break;
        }
        default:
            std::cout << "Invalid choice\n";
            break;
    }

    }while(choice != 4);
    return 0;
}

