//
// Created by preston on 10/22/2023.
//

#include <gtest/gtest.h>
#include "PointInteger.h"

TEST(Point, NotEquals) {
    PointInteger a(3, -7, 5, 7);
    PointInteger b(18, 77, 5, 7);

    ASSERT_TRUE(a != b);
    ASSERT_FALSE(a != a);
}

TEST(Point, OnCurve) {
    ASSERT_ANY_THROW(PointInteger a(-2, 4, 5, 7));
    PointInteger b(3, 7, 5, 7);
    PointInteger c(18, 77, 5, 7);
}

TEST(Point, Add0) {
    PointInteger a = PointInteger(0, 0, 5, 7, true);
    PointInteger b = PointInteger(2, 5, 5, 7);
    PointInteger c = PointInteger(2, -5, 5, 7);

    ASSERT_EQ(a + b, b);
    ASSERT_EQ(b + a, b);
    ASSERT_EQ(b + c, a);
}

TEST(Point, Add1) {
    PointInteger a = PointInteger(3, 7, 5, 7);
    PointInteger b = PointInteger(-1, -1, 5, 7);

    ASSERT_EQ(a + b, PointInteger(2, -5, 5, 7));
}

TEST(Point, Add2) {
    PointInteger a = PointInteger(-1, 1, 5, 7);

    ASSERT_EQ(a + a, PointInteger(18, -77, 5, 7));
}