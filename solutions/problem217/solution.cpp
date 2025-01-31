#include "solution.hpp"
#include <vector>
#include <unordered_set>


bool Solution::containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> contains;
        
        for(auto i:nums){
            if(contains.find(i)==contains.end()){
                contains.insert(i);
            }else{
                return true;
            }

        }
       return false; 
    }
