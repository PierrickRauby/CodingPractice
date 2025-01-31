#include "solution.hpp"
#include <vector>

int Solution::singleNumber(std::vector<int>& nums) {
        int a=0;
        for(int i:nums){
           a^=i; 
        }
       return a;
    }

