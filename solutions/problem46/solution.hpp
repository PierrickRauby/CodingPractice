#ifndef PROBLEM46_MAIN_H
#define PROBLEM46_MAIN_H
#include <set>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums);

private:
    void backtrack(const std::vector<int>& nums, std::vector<int>& sol,std::vector<std::vector<int>>& ans,std::set<int>& used);
};

#endif // PROBLEM46_MAIN_H
