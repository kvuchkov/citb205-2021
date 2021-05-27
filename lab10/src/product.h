#ifndef LAB1_PRODUCT_H
#define LAB1_PRODUCT_H

#include <string>

using std::string;

class Product {
public:
    Product(const Product &other);
    Product(int id, string name, double price);
    int getID() const;
    double getPrice() const;
    string getName() const;
private:
    int id;
    double price;
    string name;
};


#endif //LAB1_PRODUCT_H
