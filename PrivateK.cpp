//
// Created by preston on 10/22/2023.
//

#include "PrivateK.h"

PrivateK::PrivateK(const Integer& secret) : secret(secret), point(S256Point(Gx, Gy) * secret) { }

Signature PrivateK::sign(const Integer &z) {
    AutoSeededRandomPool rng;
    Integer k;
    k.Randomize(rng, 0, N);
    Integer r = (S256Point(Gx, Gy) * k).getX().getNum();
    Integer k_inv = a_exp_b_mod_c(k, N - 2, N);
    Integer s = ((z + r * this->secret) * k_inv) % N;
    if (s > N / 2) {
        s = N - s;
    }
    return { r, s };
}

ostream &operator<<(ostream &os, const PrivateK &a) {
    os << std::hex << a.secret << std::endl;
    return os;
}

S256Point PrivateK::getPoint() const {
    return point;
}
