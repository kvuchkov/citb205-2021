#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// account.h
class Account
{
    // PUT YOUR CODE HERE: only member function declarations + member varibales. !!! Function definitions should be implemented after the main function !!!
public:
    Account(const string & number, const string & owner, double balance);
    const string & getNumber() const;
    const string & getOwner() const;
    double getBalance() const;
private:
    string number;
    string owner;
    double balance;
};
// ---------

// bank.h
class Bank
{
public:
    const Account * findByNumber(string number);
    const Account * findByOwner(string name);
    bool load(const string &path);
    bool wire(double amount, string source, string dest, string &error);
};
// ---------

void showAccountInformation(ostream &out, const Account *acc) {
    out << fixed << setprecision(2);
    out << acc->getNumber() << " (" << acc->getOwner() <<  "): $" << acc->getBalance() << endl;
}

// DO NOT CHANGE the printUsage and main functions

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

    if (argv[1] == "-h" || argv[1] == "--help")
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

    string cmd;
    while (cin >> cmd) {
        if (cmd == "wire") {
            double amount;
            string source, dest;
            cin >> amount >> source >> dest;
            string error;
            bool wired = bank.wire(amount, source, dest, error);
            if (!wired) {
                cout << "Cannot wire amount: " << error << endl;
            }
            else {
                cout << amount << " was wired successfully." << endl;
            }
        } else if (cmd == "balance") {
            string term;
            cin >> term;
            const Account * acc = bank.findByNumber(term);
            if (!acc) {
                acc = bank.findByOwner(term);
            }
            if (!acc) {
                cout << "Cannot find account for " << term << endl;
            }
        }
    }

    return 0;
}

// PUT YOUR CODE HERE: member function definitions
Account::Account(const string & number, const string & owner, double balance) : number(number), owner(owner), balance(balance) {

}
const string & Account::getNumber() const
{
    return number;
}
const string & Account::getOwner() const
{
    return owner;
}
double Account::getBalance() const
{
    return balance;
}

// ---------