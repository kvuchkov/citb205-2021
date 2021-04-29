#include "product.h"

Product::Product(string name, double price): name(name), price(price) {
}

double Product::getPrice() {
    return price;
}