#include "solution.hpp"
#include <vector>
#include <climits>

int Solution::findClosestNumber(std::vector<int> &nums)
{
    int closest = INT_MAX; // only storing positive numbers
    bool positive;         // keep the sign separately
    for (auto i : nums)
    {
        if (i > 0)
        {
            if (closest >= i)
            {
                closest = i;
                positive = true;
            }
        }
        else
        {
            if (closest > (-i))
            {
                closest = -i;
                positive = false;
            }
        }
    }
    if (positive)
    {
        return closest;
    }
    else
    {
        return -closest;
    }
}
