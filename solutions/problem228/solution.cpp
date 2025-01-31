#include "solution.hpp"
#include <vector>
#include <string>

  std::vector<std::string> Solution::summaryRanges(std::vector<int>& nums) {
        int startIndex;
        std::vector<std::string> res;
        int i=0;
        if(nums.size()==1){
                 res.push_back(std::to_string(nums[0]));
                 return res;
        }
        while(i<nums.size()){
            startIndex=i;
            while((i+1<nums.size())&&(nums[i+1]==nums[i]+1)){
               i++;
            }
            if(nums[startIndex]==nums[i]){
                 res.push_back(std::to_string(nums[startIndex]));
            }else{
                 res.push_back(std::to_string(nums[startIndex])+"->"+std::to_string(nums[i]));
            }
            i++;
        }
       return res;
    }

