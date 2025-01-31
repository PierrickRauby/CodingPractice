#include "solution.hpp"
#include <vector>
#include <algorithm>

std::vector<bool> Solution::kidsWithCandies(std::vector<int> &candies, int extraCandies)
{
    // get the greatest number of candies
    std::vector<bool> res;
    int maxCandies = *std::max_element(candies.begin(), candies.end());
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies[i] + extraCandies >= maxCandies)
        {
            res.push_back(true);
        }
        else
        { // not the greatest numbers of candies
            res.push_back(false);
        }
    }
    return res;
}

// Your implementation here
