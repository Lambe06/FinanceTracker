#include "Wallet.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

Wallet::Wallet() {}

void Wallet::addTransaction(double amount, const std::string& label, const std::string& date) {
    history.emplace_back(amount, label, date);
}

int Wallet::getSize() const {
    return history.size();
}

double Wallet::getTotalBalance() const {
    double balance = 0; 
    for(size_t i = 0; i < history.size(); i++) {
        balance += history[i].getAmount();
    }
    return balance; 
}

double Wallet::getBalanceByCategory(const std::string& category) const {
    double balance = 0; 
    bool found = false; 

    for(size_t i = 0; i < history.size(); i++) {
        if(history[i].getLabel() == category) {
            balance += history[i].getAmount();
            found = true;
        }
    }

    if(found == false)
    {
        std::cout << "Warning: Category " << category << " not found in history..." << std::endl; 
    }

    return balance; 
}

const Transaction& Wallet::getTransaction(int index) {
    return history.at(index);
}

void Wallet::showHistory() const {
    std::cout << "\n-- WALLET HISTORY --" << std::endl; 
    for(size_t i = 0; i < history.size(); i++) {
        std::cout << "Transaction No. " << i + 1 << std::endl;
        std::cout << "Date: " << history[i].getDate() << std::endl;
        std::cout << "Category: " << history[i].getLabel() << std::endl;
        std::cout << "Amount: " << history[i].getAmount() << " Euro" << std::endl;
        std::cout << "----------------------------------------------" << std::endl; 
    }
}

void Wallet::appendLastTransactionToFile(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::app); // Open in append mode

    if(!outFile) {
        std::cerr << "Error: Could not open or create file " << filename << std::endl; 
        return;
    }

    if (!history.empty()) {
        const Transaction& t = history.back();
        outFile << t.getAmount() << "," << t.getLabel() << "," << t.getDate() << "\n";
    }

    outFile.close();
    std::cout << "Transaction successfully appended to " << filename << std::endl; 
}

void Wallet::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile) {
         return; // File doesn't exist yet, which is fine for the first run
    }

    std::string line;
    history.clear(); 

    while (std::getline(inFile, line)) {
        if (line.empty()) continue; 

        std::stringstream ss(line); 
        std::string sAmount, label, date;

        if (std::getline(ss, sAmount, ',') &&
            std::getline(ss, label, ',') &&
            std::getline(ss, date)) {
            
            try {
                double amount = std::stod(sAmount); 
                addTransaction(amount, label, date);
            } catch (...) {
                continue; // Skip corrupted lines
            }
        }
    }
    inFile.close();
}