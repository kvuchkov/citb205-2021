#include "invoice.h"

void Invoice::add(Product product, int qty) {
    items.push_back(Item(product, qty));
}

double Invoice::subtotal() {
    double sum = 0;
    for (auto item : items) {
        sum += item.total();
    }
    return sum;
}