#include "invoice.h"

void Invoice::add(Product product, int quantity) {
    Item item(product, quantity);
    items.push_back(item);
}

double Invoice::subtotal() {
    double sum = 0;
    for (auto item : items) {
        sum += item.total();
    }
    sum -= totalDiscounts();
    return sum;
}

double Invoice::taxes() {
    return 0.1 * subtotal();
}

double Invoice::total() {
    return subtotal() + taxes();
}

vector<Item> Invoice::getItems() {
    return items;
}

void Invoice::add(Discount *discount) {
    discounts.push_back(discount);
}

double Invoice::totalDiscounts() {
    double sum = 0;
    for (auto discount : discounts) {
        sum += discount->total(items);
    }
    return sum;
}