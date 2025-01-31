#include "solution.hpp"
#include <map>
#include <string>

int Solution::romanToInt(std::string s)
{
    std::map<char, int> convertor;
    convertor['I'] = 1;
    convertor['V'] = 5;
    convertor['X'] = 10;
    convertor['L'] = 50;
    convertor['C'] = 100;
    convertor['D'] = 500;
    convertor['M'] = 1000;
    int ans{0};
    int i;
    for (i = 0; i < s.size() - 1; i++)
    {
        if (convertor[s[i]] < convertor[s[i + 1]])
        {
            ans += (convertor[s[i + 1]] - convertor[s[i]]);
            i++;
        }
        else
        {
            ans += convertor[s[i]];
        }
    }
    ans += convertor[s[i]];
    return ans;
}
