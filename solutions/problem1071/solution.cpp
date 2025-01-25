#include "main.h"
#include <string>
#include <iostream>

bool Solution::_doesDivide(std::string numStr, std::string denStr)
{
    int den = denStr.size();
    int num = numStr.size();
    if (num % den != 0)
    {
        return false;
    }
    for (int i = 0; i < num; i++)
    {
        if (numStr[i] != denStr[i % den])
        {
            return false;
        }
    }
    return true;
}

std::string Solution::gcdOfStrings(std::string str1, std::string str2)
{
    std::string res = "";
    int minLen = std::min(str1.size(), str2.size());
    int i;
    for (i = 0; i < minLen; i++)
    {
        if (str1[i] != str2[i])
        {
            // Then need to check that the res devices both str1 and str2
            break;
        }
        res = res + str1[i];
    }
    for (int j = i - 1; j >= 0; j++)
    {
        std::cout << "testing:" << str1 << "," << str2 << ":" << res << std::endl;
        if (this->_doesDivide(str1, res) & this->_doesDivide(str2, res))
        {
            std::cout << "returning "<< res << std::endl;
            return res;
        }
        else
        {
            res.pop_back();
            if(res.size()==0){
                return res;
            }
        }
    }
    std::cout << "returning "<< res << std::endl;
    return res;
}

// Your implementation here
