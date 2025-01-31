#include "solution.hpp"


void Solution::moveZeroes(std::vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            std::swap(nums[lastNonZeroFoundAt++], nums[i]);
        }
    }
}
