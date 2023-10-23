//
// Created by preston on 10/22/2023.
//

#include <gtest/gtest.h>
#include "PrivateK.h"

TEST(PrivateK, Sign) {
    AutoSeededRandomPool rng;
    Integer secret, z;
    secret.Randomize(rng, 0, N);
    z.Randomize(rng, 0, Integer::Power2(256));

    PrivateK pk = PrivateK(secret);
    Signature sig = pk.sign(z);

    ASSERT_TRUE(pk.getPoint().verify(z, sig));
}