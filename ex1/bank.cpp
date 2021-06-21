#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Transaction.h
class Transaction
{
    // PUT YOUR CODE HERE: only member function declarations + member varibales
};
// ---------

// account.h
class Account
{
    // PUT YOUR CODE HERE: only member function declarations + member varibales
};
// ---------

// Report.h
class Report
{
    // PUT YOUR CODE HERE: only member function declarations + member varibales
};
// ---------

// DO NOT CHANGE the main function
int main(int argc, char *argv[])
{
    Account alan("AAA", "Alan Fiction");
    Account bob("BBB", "Bob Doe");
    Account chad("CC", "Chad Testings");

    alan.move(1000, bob);
    alan.move(500, chad);
    bob.move(1500, chad);

    vector<Account> accounts;
    accounts.push_back(alan);
    accounts.push_back(bob);
    accounts.push_back(chad);

    Report report;
    if (argc > 1)
    {
        ofstream fout(argv[1]);
        for (auto account : accounts) {
            report.print(fout, account);
        }
    }
    else
    {
        for (auto account : accounts) {
            report.print(cout, account);
        }
    }

    return 0;
}

// account.cpp

// PUT YOUR CODE HERE: member function definitions for the Account class

// ---------

// transaction.cpp

// PUT YOUR CODE HERE: member function definitions for the Transaction class

// ---------

// report.cpp

// PUT YOUR CODE HERE: member function definitions for the Report class

// ---------