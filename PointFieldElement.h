//
// Created by preston on 10/22/2023.
//

#ifndef ECCTBP_POINTFIELDELEMENT_H
#define ECCTBP_POINTFIELDELEMENT_H

#include <iostream>
#include <cryptopp/integer.h>
#include "FieldElement.h"

using namespace std;
using namespace CryptoPP;

class PointFieldElement {
public:
    PointFieldElement(FieldElement x, FieldElement y, FieldElement a,
                      FieldElement b, const bool& inf = false);
    PointFieldElement();

    PointFieldElement operator+(const PointFieldElement &other);
    PointFieldElement operator*(const Integer &other);

    [[nodiscard]] bool isInfinity() const;

    friend bool operator==(const PointFieldElement& lhs, const PointFieldElement& rhs);
    friend bool operator!=(const PointFieldElement& lhs, const PointFieldElement& rhs);
    friend ostream& operator<<( ostream& os, const PointFieldElement& a );

    const FieldElement &getX() const;

    const FieldElement &getY() const;

    const FieldElement &getA() const;

    const FieldElement &getB() const;

protected:
    bool infinity{};
    FieldElement x;
    FieldElement y;
    FieldElement a;
    FieldElement b;
};


#endif //ECCTBP_POINTFIELDELEMENT_H
