#ifndef PROBLEM151_MAIN_H
#define PROBLEM151_MAIN_H
#include <string>
#include <vector>

class Solution {
public:
    std::string reverseWords(std::string s);
    std::vector<std::string> extractWordsFromString(const std::string& s);
    std::string generateReverseStringFromWords(const std::vector<std::string>& s);
};

#endif // PROBLEM151_MAIN_H
