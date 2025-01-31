#include "solution.hpp"
#include <string>
#include <iostream>

bool Solution::isSubsequence(std::string s, std::string t){
    if(s.size()==0){
        return true;
    }
    int i{0};
    int j{0};
    for (j = 0; j < t.size(); j++)
    {
        if (s[i] == t[j])
        {
            std::cout << "j,t[j]=" << j << "," << t[j] << std::endl;
            std::cout << "i,s[i]=" << i << "," << s[i] << std::endl;
            i++;
            if (i == s.size())
            {
                return true;
            }
        }
    }
    return false;
}
