#include "solution.hpp"
#include <stack>
#include <string>
#include <algorithm>

std::string Solution::removeStars(std::string s)
{
    std::string res = "";
    std::stack<char> buffer;
    for (auto c : s)
    {
        if (c != '*')
        {
            buffer.push(c);
        }
        else
        {
            buffer.pop();
        }
    }
    while (buffer.size() != 0)
    {
        // res=buffer.top()+res;
        res.push_back(buffer.top());
        buffer.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
