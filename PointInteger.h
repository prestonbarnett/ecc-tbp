//
// Created by preston on 10/22/2023.
//

#ifndef ECCTBP_POINTINTEGER_H
#define ECCTBP_POINTINTEGER_H

#include <iostream>
#include <cryptopp/integer.h>

using namespace std;
using namespace CryptoPP;

class PointInteger {
public:
    PointInteger(const Integer& x, const Integer& y, const Integer& a, const Integer& b, const bool& inf = false);

    PointInteger operator+(const PointInteger &other);

    friend bool operator==(const PointInteger& lhs, const PointInteger& rhs);
    friend bool operator!=(const PointInteger& lhs, const PointInteger& rhs);
    friend ostream& operator<<( ostream& os, const PointInteger& a );
private:
    bool infinity;
    Integer x;
    Integer y;
    Integer a;
    Integer b;
};


#endif //ECCTBP_POINTINTEGER_H
