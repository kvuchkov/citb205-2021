#ifndef LAB1_ITEM_H
#define LAB1_ITEM_H


#include "product.h"

class Item {
public:
    Item(const Product *product, int quantity);
    double total() const;
    int getQuantity() const;
    const Product & getProduct() const;
    void remove(int qty);
    void add(int qty);
private:
    const Product *product;
    int quantity;
};


#endif //LAB1_ITEM_H
