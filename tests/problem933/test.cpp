#include <gtest/gtest.h>
#include "../main.h"
#include <vector>

TEST(RecentCounter, BasicTest)
{
    // Inputs
    RecentCounter obj = RecentCounter();
    std::vector<int> input{1, 100, 3001, 3002};
    std::vector<int> res{};
    std::vector<int> expectedRes{1, 2, 3, 3};
    for (auto i : input)
    {
        res.push_back(obj.ping(i));
    }
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
