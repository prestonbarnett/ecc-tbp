//
// Created by preston on 10/22/2023.
//

#ifndef ECCTBP_SIGNATURE_H
#define ECCTBP_SIGNATURE_H

#include <iostream>
#include <cryptopp/integer.h>

using namespace std;
using namespace CryptoPP;


class Signature {
public:
    Signature(const Integer& r, const Integer& s);
    Integer getR();
    Integer getS();
private:
    Integer r;
    Integer s;
};


#endif //ECCTBP_SIGNATURE_H
