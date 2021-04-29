#ifndef LAB1_INVOICE_H
#define LAB1_INVOICE_H


#include <vector>
#include "product.h"
#include "item.h"
#include "discount.h"

using std::vector;

class Invoice {
public:
    void add(Product product, int quantity);
    void add(Discount *discount);
    double subtotal();
    double taxes();
    double total();
    double totalDiscounts();
    vector<Item> getItems();
private:
    vector<Item> items;
    vector<Discount*> discounts;
};


#endif //LAB1_INVOICE_H
