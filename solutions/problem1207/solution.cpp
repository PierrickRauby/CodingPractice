#include "solution.hpp"
#include <set>
#include <map>
#include <vector>


    bool Solution::uniqueOccurrences(std::vector<int>& arr) {
        std::set<int> occurence;
        std::map<int,int> occurenceCounter; 
        for(int i: arr){
            if(occurenceCounter.find(i)==occurenceCounter.end()){
               occurenceCounter[i]=0;
            }else{
               occurenceCounter[i]+=1;
            }
        }

        for(auto c : occurenceCounter){
            if(occurence.find(c.second)==occurence.end()){
            occurence.insert(c.second);
            }else{
                return false;
            }

        }
        return true;
        
    }
