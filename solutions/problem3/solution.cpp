#include "solution.hpp"
#include <string>
#include <set>

int Solution::lengthOfLongestSubstring(std::string s)
{
    std::set<char> subString;
    int r, l{0};
    int maxSubString{0}, curSubString{0};
    for (r = 0; r < s.size(); r++)
    {
        if (subString.count(s[r]) == 0)
        {
            subString.insert(s[r]);
            curSubString = r - l + 1;
            if (curSubString > maxSubString)
            {
                maxSubString = curSubString;
            }
        }
        else
        {
            while (subString.count(s[r]) != 0)
            {
                subString.erase(s[l]);
                l++;
            }
            subString.insert(s[r]);
        }
    }
    return maxSubString;
}
