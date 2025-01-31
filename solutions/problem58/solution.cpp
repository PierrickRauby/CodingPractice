#include "solution.hpp"
#include <string>


int Solution::lengthOfLastWord(std::string s) {
       int tmp{0}; 
       int res{0};
       for(auto c:s){
        if(c!=' '){
            tmp++;
            res=tmp;
        }else{
            tmp=0;
        }
       }
       return res;
    }
