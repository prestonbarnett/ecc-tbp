//
// Created by preston on 10/22/2023.
//

#ifndef ECCTBP_FIELDELEMENT_H
#define ECCTBP_FIELDELEMENT_H

#include <iostream>
#include <cryptopp/integer.h>

using namespace std;
using namespace CryptoPP;

class FieldElement {
public:
    FieldElement(const Integer& num, const Integer& prime);
    FieldElement();

    FieldElement operator+(const FieldElement &other);
    FieldElement operator-(const FieldElement &other);
    FieldElement operator*(const FieldElement &other);
    FieldElement operator*(const Integer& other);
    FieldElement operator*(int other);
    FieldElement operator/(const FieldElement &other);
    FieldElement power(const Integer& exp);

    friend bool operator==(const FieldElement& lhs, const FieldElement& rhs);
    friend bool operator!=(const FieldElement& lhs, const FieldElement& rhs);
    friend ostream& operator<<( ostream& os, const FieldElement& a );

    [[nodiscard]] Integer getNum() const;
    [[nodiscard]] Integer getPrime() const;

private:
    Integer num;
    Integer prime;
};


#endif //ECCTBP_FIELDELEMENT_H
