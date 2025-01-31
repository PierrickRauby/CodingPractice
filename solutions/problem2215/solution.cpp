#include "solution.hpp"
#include <vector>
#include <set>
#include <algorithm>

    int Solution::binarySearch(std::vector<int>&nums,int target){
       int left=0;
       int right=nums.size()-1;
        int mid;
       while(left<=right){
        mid=left+(right-left)/2;
       if(nums[mid]==target){
        return mid;
       }else if(nums[mid]<target){
        left=mid+1;
       }else{
        right=mid-1;
       }}
       return -1;
    }

    std::vector<std::vector<int>> Solution::findDifference(std::vector<int>& nums1,
                                                 std::vector<int>& nums2) {
        std::vector<std::vector<int>> res(2);
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::set<int> comonNums;

        for (int i = 0; i < nums1.size(); i++) {
            if((i==0)||(nums1[i]>nums1[i-1])){//skip duplicates
            if (binarySearch(nums2,nums1[i])<0){//nums1[i] is not in nums2
            res[0].push_back(nums1[i]);
            }else{//nums1[i] is in nums2
            comonNums.insert(nums1[i]);
            }
            }
        }

        for (int i = 0; i < nums2.size(); i++) {
            if((i==0)||(nums2[i]>nums2[i-1])){//skip duplicates
            if(comonNums.find(nums2[i])==comonNums.end()){//nums2[i] is not in num1
            res[1].push_back(nums2[i]);
            }
            }
        }
        return res;
    }
