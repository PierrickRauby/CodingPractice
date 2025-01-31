#include "solution.hpp"
#include <vector>
#include <string>
#include <iostream>

    std::vector<std::string> Solution::extractWordsFromString(const std::string& s) {
        std::vector<std::string> res;
        std::string currentWord = "";
        bool insideWord = 0;
        for (auto c : s) {
            if (c == ' ') {
                std::cout << "space detected" << std::endl;
                if (insideWord == 1) {
                    if (currentWord != "") // We had already found a word
                    {
                        res.push_back(currentWord);
                        currentWord = "";
                        insideWord = false;
                    }
                }
            } else {
                currentWord += c;
                insideWord = true;
            }
        }
        if (insideWord == 1) {
            if (currentWord != "") // We had already found a word
            {
                res.push_back(currentWord);
                currentWord = "";
                insideWord = false;
            }
        }

        return res;
    }

    std::string Solution::generateReverseStringFromWords(const std::vector<std::string>& input)
    {
        std::string res=input[0];//There is at least 1 word

        if(input.size()>2){//if there is strickly more than 3 words 
        for(int i=1;i<input.size()-1;i++){
            res=input[i]+" "+res;
        }

        }
        //last word to be place in front
        if(input.size()>1){//if there is strickly more than 2 words 
            res=input[input.size()-1]+" "+res;

        } 
        return res;
    }

    std::string Solution::reverseWords(std::string s) {

        std::vector<std::string> words = extractWordsFromString(s);
        std::string res = generateReverseStringFromWords(words);
        return res;
    }
