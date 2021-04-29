#include "product.h"

Product::Product(string name, double price) : name(name) {
    this->price = price;
}
double Product::getPrice() const {
    return price;
}

string Product::getName() {
    return name;
}