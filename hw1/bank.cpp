#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// account.h
class Account
{
    // PUT YOUR CODE HERE: only member function declarations + member varibales
};
// ---------

// wire_transfer.h
class WireTransfer
{
    // PUT YOUR CODE HERE: only member function declarations + member varibales
};
// ---------

// bank.h
class Bank
{
    // PUT YOUR CODE HERE: only member function declarations + member varibales
};
// ---------

// logger.h
class Logger
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

// ---------

// wire_transfer.cpp

// PUT YOUR CODE HERE: member function definitions for the WireTransfer class

// ---------

// bank.cpp

// PUT YOUR CODE HERE: member function definitions for the Bank class

// ---------

// logger.cpp

// PUT YOUR CODE HERE: member function definitions for the Logger class

// ---------