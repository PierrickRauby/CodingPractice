#include <gtest/gtest.h>
#include "solution.hpp"

TEST(DefangIPTest, BasicTest) {
    EXPECT_EQ(defangIP("1.1.1.1"), "1[.]1[.]1[.]1");
    EXPECT_EQ(defangIP("255.100.50.0"), "255[.]100[.]50[.]0");
}

TEST(DefangIPTest, Empty) {
    EXPECT_EQ(defangIP(""), "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
