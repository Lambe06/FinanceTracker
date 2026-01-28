#ifndef WALLET_H
#define WALLET_H

#include <vector>
#include <string>
#include <iostream>
#include "Transaction.h"

class Wallet {
private:
    std::vector<Transaction> history;

public:
    // Constructor
    Wallet();

    // Core logic methods
    void addTransaction(double amount, const std::string& label, const std::string& date);
    int getSize() const;
    double getTotalBalance() const;
    double getBalanceByCategory(const std::string& category) const;
    const Transaction& getTransaction(int index);
    void showHistory() const;

    // File management methods
    void saveToFile(const std::string& filename) const; // Full rewrite
    void appendLastTransactionToFile(const std::string& filename) const; // Append only last
    void loadFromFile(const std::string& filename);
};

#endif