#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

// PUT YOUR CODE HERE IN THE APPROPRIATE FILE SECTION 
// - only member function declarations + member varibales. 
// !!! Function definitions should be implemented after the main function !!!

// account.h
class Account
{

};
// ---------

// bank.h
class Bank
{

};
// ---------

// DO NOT CHANGE showAccountInformation, printUsage or main
// ========================================================
void showAccountInformation(ostream &out, const Account *acc)
{
    out << fixed << setprecision(2);
    out << acc->getNumber() << " (" << acc->getOwner() << "): $" << acc->getBalance() << endl;
}

void printUsage()
{
    cout << "Usage: bank [path]" << endl
         << "\tpath - path to a CSV file with accounts" << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Invalid number of arguments: " << argc << endl;
        printUsage();
        return -1;
    }

    if (strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0)
    {
        printUsage();
        return 0;
    }

    string pathToAccountsFile = argv[1];

    Bank bank;
    bool loaded = bank.load(pathToAccountsFile);
    if (!loaded)
    {
        cout << "Cannot load accounts from " << pathToAccountsFile << endl;
        return -2;
    }

    cout << "Accounts loaded" << endl;

    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "wire")
        {
            double amount;
            string source, dest;
            cin >> amount >> source >> dest;
            string error;
            bool wired = bank.wire(amount, source, dest, error);
            if (!wired)
            {
                cout << "Cannot wire amount: " << error << endl;
            }
            else
            {
                cout << amount << " was wired successfully" << endl;
            }
        }
        else if (cmd == "show")
        {
            string term, nop;
            getline(cin, nop, ' ');
            getline(cin, term);
            const Account *acc = bank.findByNumber(term);
            if (!acc)
            {
                acc = bank.findByOwner(term);
            }
            if (!acc)
            {
                cout << "Cannot find account for " << term << endl;
                continue;
            }
            showAccountInformation(cout, acc);
        }
    }

    return 0;
}
// ========================================================

// PUT YOUR CODE HERE BELOW IN THE APPROPRIATE FILE SECTION

// account.cpp

// ---------

// bank.cpp

// ---------