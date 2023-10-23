//
// Created by preston on 10/22/2023.
//

#ifndef ECCTBP_S256FIELD_H
#define ECCTBP_S256FIELD_H

#include <iostream>
#include <cryptopp/integer.h>
#include "FieldElement.h"

using namespace std;
using namespace CryptoPP;

const Integer P = Integer::Power2(256) - Integer::Power2(32) - 977;

class S256Field : public FieldElement {
public:
    explicit S256Field(const Integer& num);
    friend ostream& operator<<( ostream& os, const S256Field& a );
};


#endif //ECCTBP_S256FIELD_H
