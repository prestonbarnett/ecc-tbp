//
// Created by preston on 10/22/2023.
//

#include <gtest/gtest.h>
#include "FieldElement.h"

TEST(FieldElement, NotEquals) {
    FieldElement a(2, 31);
    FieldElement b(2, 31);
    FieldElement c(15, 31);

    ASSERT_EQ(a, b);
    ASSERT_TRUE(a != c);
    ASSERT_FALSE(a != b);
}

TEST(FieldElement, Addition) {
    FieldElement a(2, 31);
    FieldElement b(15, 31);

    ASSERT_EQ(a + b, FieldElement(17, 31));

    a = FieldElement(17, 31);
    b = FieldElement(21, 31);

    ASSERT_EQ(a + b, FieldElement(7, 31));
}

TEST(FieldElement, Subtraction) {
    FieldElement a(29, 31);
    FieldElement b(4, 31);

    ASSERT_EQ(a - b, FieldElement(25, 31));

    a = FieldElement(15, 31);
    b = FieldElement(30, 31);

    ASSERT_EQ(a - b, FieldElement(16, 31));
}

TEST(FieldElement, Mulitiplication) {
    FieldElement a(24, 31);
    FieldElement b(19, 31);

    ASSERT_EQ(a * b, FieldElement(22, 31));
}

TEST(FieldElement, Power) {
    FieldElement a(17, 31);

    ASSERT_EQ(a.power(3), FieldElement(15, 31));

    a = FieldElement(5, 31);
    FieldElement b(18, 31);

    ASSERT_EQ(a.power(5) * b, FieldElement(16, 31));
}

TEST(FieldElement, Division) {
    FieldElement a(3, 31);
    FieldElement b(24, 31);

    ASSERT_EQ(a / b, FieldElement(4, 31));

    a = FieldElement(17, 31);

    ASSERT_EQ(a.power(-3), FieldElement(29, 31));

    a = FieldElement(4, 31);
    b = FieldElement(11, 31);

    ASSERT_EQ(a.power(-4) * b, FieldElement(13, 31));
}