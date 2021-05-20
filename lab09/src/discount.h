#ifndef DISCOUNT_H
#define DISCOUNT_H
#include <vector>
#include "item.h"

using std::vector;

class Discount {
public:
    virtual double total(const vector<Item> &items) =0;
};

class FixedDiscount : public Discount {
public:
    FixedDiscount(double amount);
    double total(const vector<Item> &items);
private:
    double amount;
};

class PercentageDiscount : public Discount {
public:
    PercentageDiscount(int percentange);
    double total(const vector<Item> &items);
private:
    int percentage;
};


#endif //DISCOUNT_H