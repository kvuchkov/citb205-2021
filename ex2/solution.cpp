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
    Account(const string &number, const string &owner, int balance);
    const string &getNumber() const;
    const string &getOwner() const;
    int getBalance() const;
    void credit(int amount);
    void debit(int amount);

private:
    string number;
    string owner;
    int balance;
};
// ---------

// bank.h
class Bank
{
public:
    Bank(int tax);
    Account *findByNumber(string number);
    Account *findByOwner(string name);
    bool load(const string &path);
    bool wire(string source, string dest, int amount, string &error);

private:
    vector<Account *> accounts;
    int tax;
};
// ---------

// DO NOT CHANGE showAccountInformation, printUsage or main

void showAccountInformation(ostream &out, const Account *acc)
{
    out << fixed << setprecision(2);
    out << acc->getNumber() << " (" << acc->getOwner() << "): $" << acc->getBalance() / 100.0 << endl;
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

    Bank bank(250);
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
            int amount;
            string source, dest;
            cin >> amount >> source >> dest;
            string error;
            bool wired = bank.wire(source, dest, amount, error);
            if (!wired)
            {
                cout << "Cannot wire amount: " << error << endl;
            }
            else
            {
                cout << "$" << amount / 100.0 << " was wired successfully" << endl;
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
Account::Account(const string &number, const string &owner, int balance) : number(number), owner(owner), balance(balance)
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
int Account::getBalance() const
{
    return balance;
}

void Account::credit(int amount)
{
    balance -= amount;
}
void Account::debit(int amount)
{
    balance += amount;
}

// ---------

// bank.cpp
Bank::Bank(int tax) : tax(tax) {}

Account *Bank::findByNumber(string number)
{
    for (auto acc : accounts)
    {
        if (acc->getNumber() == number)
        {
            return acc;
        }
    }
    return NULL;
}
Account *Bank::findByOwner(string name)
{
    for (auto acc : accounts)
    {
        if (acc->getOwner() == name)
        {
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
        int balance;

        getline(ss, number, ',');
        getline(ss, name, ',');
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
bool Bank::wire(string source, string dest, int amount, string &error)
{
    auto sAcc = findByNumber(source);
    if (!sAcc)
        sAcc = findByOwner(source);
    if (!sAcc)
    {
        error = "cannot find source account";
        return false;
    }
    auto dAcc = findByNumber(dest);
    if (!dAcc)
        dAcc = findByOwner(dest);
    if (!dAcc)
    {
        error = "cannot find destination account";
        return false;
    }

    if (sAcc->getBalance() < amount + tax)
    {
        error = "insufficient funds";
        return false;
    }

    sAcc->credit(amount+tax);
    dAcc->debit(amount);

    return true;
}
// ---------
