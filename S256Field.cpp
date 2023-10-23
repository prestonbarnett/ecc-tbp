//
// Created by preston on 10/22/2023.
//

#include "S256Field.h"

S256Field::S256Field(const Integer& num) : FieldElement(num, P) {
}

ostream &operator<<(ostream &os, const S256Field &a) {
    os << std::hex << a.getNum();
    return os;
}
