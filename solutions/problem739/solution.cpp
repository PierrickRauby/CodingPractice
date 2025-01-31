#include "solution.hpp"
#include <vector>
#include <stack>

    std::vector<int> Solution::dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(),0);
        std::stack<int> records;
        int temp;
        for(int i=0; i<temperatures.size();i++){
            temp=temperatures[i];
            while(!records.empty()&& temp>temperatures[records.top()]){
                res[records.top()]=i-records.top(); //delta indexes
                records.pop();
            }
            records.push(i); // place the new date

        }
       return res; 
    }

