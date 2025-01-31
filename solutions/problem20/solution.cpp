#include "solution.hpp"
#include <string>
#include <stack>

bool Solution::isValid(std::string s){
      std::stack<char> Parentheses;  
      for(auto c:s)// iterate over S once and check if there is any issues
      {
        if(c=='(' || c=='{' || c=='['){//opening brackets
          Parentheses.push(c);
        }else{
           if(Parentheses.empty()){
            return false;
           }
           if((c==')'&& Parentheses.top()=='(')
           ||(c=='}'&& Parentheses.top()=='{')
           ||(c==']'&& Parentheses.top()=='[')){
            Parentheses.pop();// we have a valid parenthese
           }else{
            return false;
           }
        }
      }
    if(Parentheses.empty()) {
        return true;
    }
    return false;
     
    }
