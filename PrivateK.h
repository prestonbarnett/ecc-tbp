//
// Created by preston on 10/22/2023.
//

#ifndef ECCTBP_PRIVATEK_H
#define ECCTBP_PRIVATEK_H

#include <iostream>
#include <cryptopp/integer.h>
#include <cryptopp/osrng.h>
#include "S256Point.h"

using namespace std;
using namespace CryptoPP;

class PrivateK {
public:
    explicit PrivateK(const Integer& secret);
    Signature sign(const Integer& z);
    friend ostream& operator<<( ostream& os, const PrivateK& a );

    [[nodiscard]] S256Point getPoint() const;
private:
    Integer secret;
    S256Point point;
};


#endif //ECCTBP_PRIVATEK_H
