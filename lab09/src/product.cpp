#include "product.h"
#include <iostream>
using std::cerr;
using std::endl;

Product::Product(const Product &other) {
    price = other.price;
    name = other.name;
    cerr << "::COPY PRODUCT(" << other.name << ")" << endl;
}

Product::Product(string name, double price) : name(name) {
    this->price = price;
}
double Product::getPrice() const {
    return price;
}

string Product::getName() const {
    return name;
}