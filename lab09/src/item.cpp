#include "item.h"

Item::Item(const Product *product, int quantity) : product(product) {
    this->quantity = quantity;
}

double Item::total() const {
    return product->getPrice() * quantity;
}

int Item::getQuantity() const {
    return quantity;
}

const Product & Item::getProduct() const {
    return *product;
}
