#include "solution.hpp"
#include <string>
#include <iostream>

std::string Solution::mergeAlternately(std::string word1, std::string word2)
{
    int i;
    std::string res = "";
    for (i = 0; i < word1.size(); i++)
    {
        res = res + word1[i];
        if (i < word2.size())
        {
            res = res + word2[i];
        }

        std::cout << res << std::endl;
    }
    while (i < word2.size())
    {
        res = res + word2[i];
        i++;
    }
    return res;
}
