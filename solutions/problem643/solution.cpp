#include "solution.hpp"
#include <iostream>
#include <vector>
double Solution::findMaxAverage(std::vector<int>& nums, int k){
    int startIndex{0};
    double maxSum=0.0
    double currentSum=0.0;
    // get the sum for the first array
    for(int i=startIndex;i<startIndex+k;i++){
            currentSum+=nums[i];
    }
    maxSum=currentSum;

    for(startIndex=0;startIndex+k<nums.size();startIndex++){
        currentSum=currentSum-nums[startIndex]+nums[startIndex+k];
        if(currentSum>maxSum){
            maxSum=currentSum;
        }
    }
return maxSum/k;
}
