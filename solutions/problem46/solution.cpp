#include "solution.hpp"
#include <set>
#include <vector>

std::vector<std::vector<int>> Solution::permute(std::vector<int>& nums) {
    std::vector<int> sol;
    std::vector<std::vector<int>>ans;
    std::set<int> used;
    this->backtrack(nums,sol,ans,used);
    return  ans;

}

void Solution::backtrack(const std::vector<int>& nums, std::vector<int>& sol,std::vector<std::vector<int>>& ans,std::set<int>& used){
    if(sol.size()==nums.size()){//we are at a leaf
    ans.push_back(sol);
    }

    for(int i=0;i<nums.size();i++){
        if(used.find(nums[i])!=used.end()){
            continue;
        }
        sol.push_back(nums[i]);
        used.insert(nums[i]);
        backtrack(nums,sol,ans,used);
        sol.pop_back();
        used.erase(nums[i]);
    }
}
