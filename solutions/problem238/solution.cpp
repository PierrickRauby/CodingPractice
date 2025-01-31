#include "solution.hpp"
#include <vector>

std::vector<int> Solution::productExceptSelf(std::vector<int> &nums)
{
    std::vector<int> ans;
    int total = 0;
    int numsContainsZeros = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            if (total == 0)
            {
                total = nums[i];
            }
            else
            {
                total = total * nums[i];
            }
        }
        else
        {
            numsContainsZeros += 1;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if ((numsContainsZeros > 1) | ((nums[i] != 0) & numsContainsZeros))
        {
            ans.push_back(0);
        }
        else if ((nums[i] != 0) & !numsContainsZeros)
        {
            ans.push_back(total / nums[i]);
        }
        else
        {
            ans.push_back(total);
        }
    }
    return ans;
}
