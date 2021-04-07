#include "item.h"

Item::Item(Product product, int qty): product(product) {
    quantity = qty;
}

double Item::total() {
    return product.getPrice() * quantity;
}