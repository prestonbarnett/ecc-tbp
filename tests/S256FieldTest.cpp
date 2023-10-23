//
// Created by preston on 10/22/2023.
//

#include <gtest/gtest.h>
#include "S256Field.h"

TEST(S256Field, Constructor) {
    ASSERT_NO_THROW(S256Field a(P - 1));
}