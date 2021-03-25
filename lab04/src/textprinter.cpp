#include "textprinter.h"

void TextPrinter::print(std::ostream &out, Invoice invoice) {
    out << invoice.subtotal() << std::endl;
}