#include "solution.hpp"
#include <vector>
#include <iostream>

int Solution::pivotIndex(std::vector<int> &nums)
{
    // first get the total sum of the array;
    int rightSum = 0;
    int leftSum = 0;
    int ret = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        rightSum += nums[i];
    }
    for (int j = 0; j < nums.size();j++ )
    {
        rightSum -= nums[j];
        std::cout << "j:" << j << " sl:" << leftSum << " sr:" << rightSum << std::endl;
        if (leftSum == rightSum)
        {
            return j;
        }
        leftSum += nums[j];
    }
    // if (leftSum == rightSum)
    //     {
    //         return nums.size()-1;
    //     }

    return ret;
}
