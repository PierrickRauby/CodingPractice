#include "solution.hpp"

#include <set>
#include <string>

int Solution::numJewelsInStones(std::string jewels, std::string stones)
{
    int ans{0};
    std::set<char> jewelsSet ;
    for (char jewel : jewels)
    {
        jewelsSet.insert(jewel);
    }
    for (char stone : stones)
    {
        if (jewelsSet.find(stone) != jewelsSet.end())
        {
            ans += 1;
        }
    }
    return ans;
}
