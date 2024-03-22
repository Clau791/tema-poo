#include <gtest/gtest.h>
#include "example.h"

TEST(SuiteName, TestName) {
    doSomething();
    EXPECT_EQ(10, 10);
    // Other assertions: https://google.github.io/googletest/reference/assertions.html#boolean
}