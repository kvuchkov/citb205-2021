#include "invoice.h"

void Invoice::add(Product *product, int quantity) {
    for (int i=0; i<items.size(); i++) {
        if (items[i].getProduct().getID() == product->getID()) {
            items[i].add(quantity);
            return;
        }
    }
    Item item(product, quantity);
    items.push_back(item);
}

void Invoice::remove(Product *product, int quantity) {
    for (int i=0; i<items.size(); i++) {
        if (items[i].getProduct().getID() == product->getID()) {
            items[i].remove(quantity);
            if (items[i].getQuantity() < 1) {
                items.erase(items.begin() + i);
            }
            return;
        }
    }
}

double Invoice::subtotal() const {
    double sum = 0;
    for (auto item : items) {
        sum += item.total();
    }
    sum -= totalDiscounts();
    return sum;
}

double Invoice::taxes() const {
    return 0.1 * subtotal();
}

double Invoice::total() const {
    return subtotal() + taxes();
}

const vector<Item> & Invoice::getItems() const {
    return items;
}

void Invoice::add(Discount *discount) {
    discounts.push_back(discount);
}

double Invoice::totalDiscounts() const {
    double sum = 0;
    for (auto discount : discounts) {
        sum += discount->total(items);
    }
    return sum;
}

void Invoice::clearDiscounts() {
    discounts.clear();
}
