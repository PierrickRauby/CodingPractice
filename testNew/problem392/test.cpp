#include <gtest/gtest.h>
#include "main.h"
#include <string>
using namespace std;
TEST(isSubsequence, BaseFalseTest) {
    string s="axc";
    string t="ahbgdc";
    Solution sol;
    bool res=sol.isSubsequence(s,t);
    EXPECT_EQ(res, false);
}

TEST(isSubsequence, BaseTrueTest) {
    string s="abc";
    string t="ahbgdc";
    Solution sol;
    bool res=sol.isSubsequence(s,t);
    EXPECT_EQ(res, true);
}

TEST(isSubsequence, EmptyTest) {
    string s="";
    string t="ahbgdc";
    Solution sol;
    bool res=sol.isSubsequence(s,t);
    EXPECT_EQ(res, true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
