FinanceTracker is a CLI application (Command Line Interface) developed in C++ for 
the simplified management of personal finances. The program allows you to track income 
and expenses, categorize transactions, and ensure data persistence through CSV files. 

The application is divided into multiple files: 

- Transaction.h -> Header file with the declarations of some methods for Transaction objects

- Wallet.h -> Header file with the declarations fo some methods for the Wallet object and for 
the management of the input/output file in CSV format. 

- Wallet.cpp -> Definitions of the Wallet.h methods 

- main.cpp -> the heart of the application, where the user can interact with the functions
explained before. 

To compile on your pc (with a compiler installed):
g++ Wallet.cpp main.cpp -o FinanceTracker (or something else as you prefer)

To run the program from CMD : 
./FinanceTracker 

Note: Make sure that all files are in a single directory! 

You don't need to create a CSV file at the first run, because if it doesn't exists, it will be 
created during the execution.





