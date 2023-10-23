//
// Created by preston on 10/22/2023.
//

#include "S256Point.h"

S256Point::S256Point(const Integer &x, const Integer &y) :
  PointFieldElement(S256Field(x), S256Field(y), S256Field(0), S256Field(7)) { }

S256Point::S256Point(const S256Field& x, const S256Field& y) :
        PointFieldElement(S256Field(x), S256Field(y), S256Field(0), S256Field(7)) { }

S256Point::S256Point(const PointFieldElement& element) : PointFieldElement(element) { }

ostream &operator<<(ostream &os, const S256Point &a) {
    if (a.infinity) {
        os << "S256Point(infinity)";
    } else {
        os << "S256Point(" << a.x << ", " << a.y << ")";
    }
    return os;
}

S256Point S256Point::operator*(const Integer &other) {
    Integer coefficient = other % N;
    return S256Point(PointFieldElement::operator*(coefficient));
}

bool S256Point::verify(const Integer& z, Signature sig) {
    Integer s_inv = a_exp_b_mod_c(sig.getS(), N - 2, N);
    Integer u = (z * s_inv) % N;
    Integer v = (sig.getR() * s_inv) % N;
    PointFieldElement total = S256Point(Gx, Gy) * u + *this * v;
    return total.getX().getNum() == sig.getR();
}
