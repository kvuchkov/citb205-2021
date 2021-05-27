#include "product.h"
#include <iostream>
using std::cerr;
using std::endl;

Product::Product(const Product &other) {
    id = other.id;
    price = other.price;
    name = other.name;
    cerr << "::COPY PRODUCT(" << other.name << ")" << endl;
}

Product::Product(int id, string name, double price) : id(id), name(name) {
    this->price = price;
}

int Product::getID() const {
    return id;
}

double Product::getPrice() const {
    return price;
}

string Product::getName() const {
    return name;
}