#include "solution.hpp"
#include <unordered_map>
#include <string>

bool Solution::isAnagram(std::string s, std::string t)
{
    std::unordered_map<char, int> lettersAvailable;
    for (char c : s)
    {
        if (lettersAvailable.find(c) == lettersAvailable.end())
        {
            lettersAvailable[c] = 1;
        }
        else
        {
            lettersAvailable[c] += 1;
        }
    }
    for (char c : t)
    {
        if (lettersAvailable.find(c) == lettersAvailable.end())
        {
            return false;
        }
        else
        {
            lettersAvailable[c] -= 1;
            if (lettersAvailable[c] < 0)
            {
                return false;
            }
        }
    }
    for (char c : s)
    {
        if (lettersAvailable[c] > 0)
        {
            return false;
        }
    }
    return true;
}
