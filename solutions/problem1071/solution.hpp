#ifndef PROBLEM1071_MAIN_H
#define PROBLEM1071_MAIN_H
#include <string>
#include <iostream>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2);

private:
    bool _doesDivide(std::string numStr, std::string denStr);
};
#endif // PROBLEM1071_MAIN_H
