#include "catalog.h"

#include <iostream>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::cerr;
using std::endl;
using std::stringstream;

Product * Catalog::get(int id) const {
    for (auto product : products) {
        if (product->getID() == id) {
            return product;
        }
    }
    return 0;
}

void Catalog::load(string path) {
   ifstream fin(path);
   if (fin.fail()) {
       cerr << "Cannot open file " << path << endl;
   }
   string line;
   string nop;
   while(getline(fin, line)) {
       stringstream ss(line);
       
       int id;
       double price;
       string name; 

       ss >> id;
       getline(ss, nop, ',');
       getline(ss, name, ',');
       ss >> price;
       if (ss.fail()) {
           cerr << "Cannot parse '" << line << "'" << endl;
           continue;
       }
       products.push_back(new Product(id, name, price));
   }
}

vector<Product *> Catalog::getProducts() const {
    return products;
}
