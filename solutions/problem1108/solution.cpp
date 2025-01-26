#include "solution.hpp"
#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ret="";
           for (char c : address){
            if(c=='.'){
                ret+="[.]";
            }else{
               ret+=c; 
            }
            std::cout<<ret<<std::endl;
           }
       return ret; 
    }
};
string defangIP(string address) {
    Solution sol;
    return sol.defangIPaddr(address);
}
