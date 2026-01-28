#include "Transaction.h"
#include "Wallet.h"
#include <iostream>
#include <string>
#include <limits>

int main() {
    Wallet w; 
    w.loadFromFile("data.csv");
    bool done = false;

    while(!done) {
        std::cout << "\nWelcome to your Personal Wallet! What would you like to do? " << std::endl;
        std::cout << "A) Insert a new Transaction" << std::endl;
        std::cout << "B) Show wallet history" << std::endl;
        std::cout << "C) Show history by category" << std::endl;
        std::cout << "D) Close the program" << std::endl;
        std::cout << "\nPlease press A, B, C or D: ";

        std::string input;
        std::cin >> input;

        // Validation: must be exactly 1 character long
        if (input.length() != 1) {
            std::cout << "Invalid input. Please enter only a single character (A, B, C, or D)." << std::endl;
            continue;
        }

        char choice = toupper(input[0]);

        if(choice == 'A') {
            double amount; 
            std::string category, date;

            std::cout << "Please insert the transaction amount: ";
            while (!(std::cin >> amount)) {
                std::cout << "Invalid input. Please enter a numeric value: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please insert the category: ";
            std::getline(std::cin, category);

            std::cout << "Please insert the date (YYYY-MM-DD): ";
            std::getline(std::cin, date);

            w.addTransaction(amount, category, date);
            w.appendLastTransactionToFile("data.csv");
            std::cout << "Transaction saved." << std::endl;

        } else if(choice == 'B') {
            w.showHistory();
            std::cout << "Total Balance: " << w.getTotalBalance() << " Euro" << std::endl;

        } else if(choice == 'C') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string category; 
            std::cout << "Insert the category name: ";
            std::getline(std::cin, category);

            double balance = w.getBalanceByCategory(category);
            std::cout << "Total for " << category << ": " << balance << " Euro" << std::endl;

        } else if(choice == 'D') {
            std::cout << "Exiting program. Goodbye!" << std::endl;
            done = true;

        } else {
            std::cout << "Character not allowed, please choose one of the options listed above." << std::endl;
        }
    }

    return 0;
}