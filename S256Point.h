//
// Created by preston on 10/22/2023.
//

#ifndef ECCTBP_S256POINT_H
#define ECCTBP_S256POINT_H

#include <iostream>
#include <cryptopp/integer.h>
#include "Signature.h"
#include "S256Field.h"
#include "PointFieldElement.h"

using namespace std;
using namespace CryptoPP;

const Integer N = Integer("0xfffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141");
const Integer Gx = Integer("0x79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798");
const Integer Gy = Integer("0x483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8");

class S256Point : public PointFieldElement {
public:
    explicit S256Point(const Integer& x, const Integer& y);
    explicit S256Point(const S256Field& x, const S256Field& y);
    explicit S256Point(const PointFieldElement& element);

    S256Point operator*(const Integer& other);

    bool verify(const Integer& z, Signature sig);

    friend ostream& operator<<( ostream& os, const S256Point& a );
};

#endif //ECCTBP_S256POINT_H
