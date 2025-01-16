#include <gtest/gtest.h>
#include "main.h"
#include <string>
using namespace std;
TEST(isSubsequence, BaseTest) {
    std::string a="abc";
    std::string b="pqr";
    string expected="apbqcr";
    Solution sol;
    std::string res=sol.mergeAlternately(a,b);
    EXPECT_EQ(res,expected );
}
TEST(isSubsequence, BaseTest2) {
    std::string a="pqr";
    std::string b="abc";
    string expected="paqbrc";
    Solution sol;
    std::string res=sol.mergeAlternately(a,b);
    EXPECT_EQ(res,expected );
}
TEST(isSubsequence,EmptyTest ) {
    std::string a="";
    std::string b="";
    string expected="";
    Solution sol;
    std::string res=sol.mergeAlternately(a,b);
    EXPECT_EQ(res,expected );
}
TEST(isSubsequence,EmptyTestWord1 ) {
    std::string a="";
    std::string b="abc";
    string expected="abc";
    Solution sol;
    std::string res=sol.mergeAlternately(a,b);
    EXPECT_EQ(res,expected );
}

TEST(isSubsequence,EmptyTestWord2 ) {
    std::string a="abc";
    std::string b="";
    string expected="abc";
    Solution sol;
    std::string res=sol.mergeAlternately(a,b);
    EXPECT_EQ(res,expected );
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
