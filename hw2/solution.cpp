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
public:
    Account(const string &number, const string &owner, double balance);
    const string &getNumber() const;
    const string &getOwner() const;
    double getBalance() const;
    void credit(double amount);
    void debit(double amount);

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
    Account *findByNumber(string number);
    Account *findByOwner(string name);
    bool load(const string &path);
    bool wire(double amount, string source, string dest, string &error);

private:
    vector<Account *> accounts;
};
// ---------

// DO NOT CHANGE showAccountInformation, printUsage or main

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

// PUT YOUR CODE HERE BELOW IN THE APPROPRIATE FILE SECTION

// account.cpp
Account::Account(const string &number, const string &owner, double balance) : number(number), owner(owner), balance(balance)
{
}
const string &Account::getNumber() const
{
    return number;
}
const string &Account::getOwner() const
{
    return owner;
}
double Account::getBalance() const
{
    return balance;
}

void Account::credit(double amount)
{
    balance -= amount;
}
void Account::debit(double amount)
{
    balance += amount;
}

// ---------

// bank.cpp
Account *Bank::findByNumber(string number)
{
    for (auto acc : accounts) {
        if (acc->getNumber() == number) {
            return acc;
        }
    }
    return NULL;
}
Account *Bank::findByOwner(string name)
{
    for (auto acc : accounts) {
        if (acc->getOwner() == name) {
            return acc;
        }
    }
    return NULL;
}
bool Bank::load(const string &path)
{
    ifstream fin(path);
    if (fin.fail())
    {
        return false;
    }

    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        string name, number;
        double balance;

        getline(ss, name, ',');
        getline(ss, number, ',');
        ss >> balance;

        if (ss.fail())
        {
            break;
        }

        cerr << " > Loaded |" << name << "|" << number << "|" << balance << "|" << endl;
        accounts.push_back(new Account(number, name, balance));
    }
    if (fin.eof())
    {
        return true;
    }
    return false;
}
bool Bank::wire(double amount, string source, string dest, string &error)
{
    auto sAcc = findByNumber(source);
    if (!sAcc)
    {
        error = "cannot find source account";
        return false;
    }
    auto dAcc = findByNumber(dest);
    if (!dAcc)
    {
        error = "cannot find destination account";
        return false;
    }

    if (sAcc->getBalance() < amount)
    {
        error = "insufficient funds";
        return false;
    }

    sAcc->credit(amount);
    dAcc->debit(amount);

    return true;
}
// ---------
