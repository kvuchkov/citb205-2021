#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// account.h
class Account
{
    // PUT YOUR CODE HERE: only member function declarations + member varibales
public:
    Account(string iban, string owner);
    string getIBAN();
    string getOwner();

private:
    string iban;
    string owner;
};
// ---------

// wire_transfer.h
class WireTransfer
{
    // PUT YOUR CODE HERE: only member function declarations + member varibales
public:
    WireTransfer(double amount, Account source, Account dest);
    Account getSource();
    Account getDestination();
    double getAmount();

private:
    Account source;
    Account dest;
    double amount;
};
// ---------

// bank.h
class Bank
{
    // PUT YOUR CODE HERE: only member function declarations + member varibales
public:
    void wire(double amount, Account source, Account dest);
    vector<WireTransfer> getTransactions();
    double total();

private:
    vector<WireTransfer> transactions;
};
// ---------

// logger.h
class Logger
{
    // PUT YOUR CODE HERE: only member function declarations + member varibales
public:
    void log(ostream &out, Bank bank);
};
// ---------

// DO NOT CHANGE the main function
int main(int argc, char *argv[])
{
    Account alan("AAA", "Alan Fiction");
    Account bob("BBB", "Bob Doe");
    Account chad("CC", "Chad Testings");

    Bank bank;
    bank.wire(100.0, alan, bob);
    bank.wire(200.0, alan, chad);
    bank.wire(150.0, bob, chad);

    Logger logger;
    if (argc > 1)
    {
        ofstream fout(argv[1]);
        logger.log(fout, bank);
    }
    else
    {
        logger.log(cout, bank);
    }

    return 0;
}

// account.cpp

// PUT YOUR CODE HERE: member function definitions for the Account class
Account::Account(string iban, string owner) : iban(iban), owner(owner) {}
string Account::getIBAN()
{
    return iban;
}
string Account::getOwner()
{
    return owner;
}
// ---------

// wire_transfer.cpp

// PUT YOUR CODE HERE: member function definitions for the WireTransfer class

WireTransfer::WireTransfer(double amount, Account source, Account dest) : amount(amount), source(source), dest(dest) {}
Account WireTransfer::getSource()
{
    return source;
}
Account WireTransfer::getDestination()
{
    return dest;
}
double WireTransfer::getAmount()
{
    return amount;
}
// ---------

// bank.cpp

// PUT YOUR CODE HERE: member function definitions for the Bank class

void Bank::wire(double amount, Account source, Account dest)
{
    transactions.push_back(WireTransfer(amount, source, dest));
}
vector<WireTransfer> Bank::getTransactions()
{
    return transactions;
}
double Bank::total()
{
    double sum = 0;
    for (auto t : transactions)
    {
        sum += t.getAmount();
    }
    return sum;
}
// ---------

// logger.cpp

// PUT YOUR CODE HERE: member function definitions for the Logger class

void Logger::log(ostream &out, Bank bank)
{
    out << fixed << setprecision(2);
    out << bank.total() << endl;
    out << "---" << endl;
    for (auto t : bank.getTransactions())
    {
        out << t.getAmount() << ":";
        out << t.getDestination().getIBAN() << "(" << t.getDestination().getOwner() << ")";
        out << "<-";
        out << t.getSource().getIBAN() << "(" << t.getSource().getOwner() << ")";
        out << endl;
    }
}

// ---------