#ifndef PROBLEM1380_MAIN_H
#define PROBLEM1380_MAIN_H
#include <vector>
#include <algorithm>

class Solution {
    private:
    bool checkIfMinAlongRow(std::vector<int>& line,int val);
    // bool checkIfMinAlongCol(std::vector<int> line);
public:
    std::vector<int> luckyNumbers (std::vector<std::vector<int>>& matrix);
};

#endif // PROBLEM1380_MAIN_H
