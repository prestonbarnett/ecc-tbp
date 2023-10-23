//
// Created by preston on 10/22/2023.
//

#include <gtest/gtest.h>
#include "PointFieldElement.h"

using namespace std;

TEST(ECCTest, OnCurve) {
    Integer prime = 223;
    FieldElement a(0, prime);
    FieldElement b(7, prime);

    vector<pair<Integer, Integer>> validPoints = {
            {192, 105},
            {17, 56},
            {1, 193}
    };

    vector<pair<Integer, Integer>> invalidPoints = {
            {200, 119},
            {42, 99},
    };

    for (auto & validPoint : validPoints) {
        FieldElement x(validPoint.first, prime);
        FieldElement y(validPoint.second, prime);
        ASSERT_NO_THROW(PointFieldElement(x, y, a, b));
    }

    for (auto & invalidPoint : invalidPoints) {
        FieldElement x(invalidPoint.first, prime);
        FieldElement y(invalidPoint.second, prime);
        ASSERT_ANY_THROW(PointFieldElement(x, y, a, b));
    }
}

TEST(ECCTest, Add) {
    Integer prime = 223;
    FieldElement a(0, prime);
    FieldElement b(7, prime);

    std::vector<std::array<Integer, 6>> additions = {
            {{192, 105, 17, 56, 170, 142}},
            {{47, 71, 117, 141, 60, 139}},
            {{143, 98, 76, 66, 47, 71}}
    };

    for (auto & addition : additions) {
        FieldElement x1(addition[0], prime);
        FieldElement y1(addition[1], prime);
        FieldElement x2(addition[2], prime);
        FieldElement y2(addition[3], prime);
        FieldElement x3(addition[4], prime);
        FieldElement y3(addition[5], prime);

        PointFieldElement p1(x1, y1, a, b);
        PointFieldElement p2(x2, y2, a, b);
        PointFieldElement p3(x3, y3, a, b);

        ASSERT_EQ(p1 + p2, p3);
    }
}

TEST(ECCTest, RMul) {
    Integer prime = 223;
    FieldElement a(0, prime);
    FieldElement b(7, prime);

    std::vector<std::array<Integer, 6>> multiplications = {
            {{2, 192, 105, 49, 71, 0}},
            {{2, 143, 98, 64, 168, 0}},
            {{2, 47, 71, 36, 111, 0}},
            {{4, 47, 71, 194, 51, 0}},
            {{8, 47, 71, 116, 55, 0}},
            {{21, 47, 71, 0, -1, -1}}
    };

    for (auto & multiplication : multiplications) {
        Integer s = multiplication[0];

        FieldElement x1(multiplication[1], prime);
        FieldElement y1(multiplication[2], prime);
        PointFieldElement p1(x1, y1, a, b);

        if (multiplication[5] != -1) {
            FieldElement x2(multiplication[3], prime);
            FieldElement y2(multiplication[4], prime);
            PointFieldElement p2 = PointFieldElement(x2, y2, a, b);

            ASSERT_EQ(p1 * s, p2);
        } else {
            FieldElement x2(1, prime);
            FieldElement y2(1, prime);
            PointFieldElement p2 = PointFieldElement(x2, y2, a, b, true);

            ASSERT_EQ(p1 * s, p2);
        }
    }
}