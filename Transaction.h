#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    double amount;
    std::string label;
    std::string date;

public:
    
    Transaction(double a, const std::string& l, const std::string& d) 
        : amount(a), label(l), date(d) {}

    double getAmount() const { return amount; }
    std::string getLabel() const { return label; }
    std::string getDate() const { return date; }
};

#endif