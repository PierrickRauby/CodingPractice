#include "main.h"
#include <vector>
#include <unordered_map>

std::vector<int> Solution::twoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> mem;
    std::vector<int> res;
    for (int i=0; i < nums.size(); i++)
    {
        if (mem.count(target - nums[i]))
        {
            res.push_back(mem[target - nums[i]]);
            res.push_back(i);
            break;
        }
        else
        {
            mem[nums[i]] = i;
        }
    }
    return res;
}