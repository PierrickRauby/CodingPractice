#include "solution.hpp"
#include <vector> 
#include <cstdlib>
    std::vector<int> Solution::sortedSquares(std::vector<int>& nums) {
        std::vector<int> ans(nums.size());
        int leftIndex=0;
        int rightIndex=nums.size()-1;
        int i=0;
        while(leftIndex<=rightIndex){
            i++;
                if(std::abs(nums[leftIndex])<std::abs(nums[rightIndex])){
                ans[nums.size()-i]=nums[rightIndex]*nums[rightIndex];
                rightIndex--;
            }else{
                ans[nums.size()-i]=nums[leftIndex]*nums[leftIndex];
                leftIndex++;
            }
        }
        return ans;
    }

