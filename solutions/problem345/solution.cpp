#include "solution.hpp"
#include <string>

    bool Solution::checkIfVowel(char c){
     std::string allowedVowels="aeiouAEIOU";
     return (allowedVowels.find(c)!=std::string::npos);
    }
    void Solution::reverseString(std::string& s){
        char tmp; 
        int mid=(int)s.size()/2;
        for(int i=0;i<mid;i++){
            tmp=s[i];
            s[i]=s[s.size()-(i+1)];
            s[s.size()-(i+1)]=tmp;
        }
    }

    std::string Solution::reverseVowels(std::string s) {
        std::string vowels;
        std::string allowedVowels="aeiouAEIOU";
        bool isVowel;
        int j=0;
        for(int i=0;i<s.size();i++){
            isVowel=checkIfVowel(s[i]);
            if(isVowel){
             vowels.push_back(s[i]);
            }
        }
        reverseString(vowels);

        for(int i=0;i<s.size();i++){
            isVowel=checkIfVowel(s[i]);
            if(isVowel){
                s[i]=vowels[j];
                j+=1;
            }
        }
       return s;
    }
