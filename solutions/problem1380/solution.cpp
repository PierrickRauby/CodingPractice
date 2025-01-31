#include "solution.hpp"
#include <vector>
#include <algorithm>

bool Solution::checkIfMinAlongRow(std::vector<int>& line,int val){
    if(val==*(std::min_element(line.begin(),line.end()))){
        return true;
    }
    return false;
}

std::vector<int> Solution::luckyNumbers(std::vector<std::vector<int>> &matrix)
{
    std::vector<int> res;
    int i, j;
    int currentMaxRowIndex;
    int currentMaxVal;
    for (j = 0; j < matrix[0].size(); j++)
    { // iterate over the cols
    currentMaxRowIndex=0;
    currentMaxVal = matrix[0][j];

    for (i = 0; i < matrix.size(); i++)
    { // iterate over the rows
        if(matrix[i][j]>currentMaxVal){
            currentMaxRowIndex = i;
            currentMaxVal = matrix[i][j];
        }
        }
        if(this->checkIfMinAlongRow(matrix[currentMaxRowIndex],currentMaxVal)){
            res.push_back(currentMaxVal);
        }
    }

    return res;
}
