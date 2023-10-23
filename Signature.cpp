//
// Created by preston on 10/22/2023.
//

#include "Signature.h"

Signature::Signature(const Integer& r, const Integer& s) : r(r), s(s) { }

Integer Signature::getR() {
    return this->r;
}

Integer Signature::getS() {
    return this->s;
}
