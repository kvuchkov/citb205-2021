#include "discount.h"

FixedDiscount::FixedDiscount(double amount) : amount(amount) {

}

double FixedDiscount::total(vector<Item> items) {
    return amount;
}

PercentageDiscount::PercentageDiscount(int percentage) : percentage(percentage) {

}

double PercentageDiscount::total(vector<Item> items) {
    double sum = 0;
    for (auto item : items) {
        sum += item.total();
    }
    return (percentage/100.0)*sum;
}