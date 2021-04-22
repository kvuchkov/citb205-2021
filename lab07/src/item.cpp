#include "item.h"

Item::Item(Product product, int quantity) : product(product) {
    this->quantity = quantity;
}

double Item::total() {
    return product.getPrice() * quantity;
}

int Item::getQuantity() {
    return quantity;
}

Product Item::getProduct() {
    return product;
}
