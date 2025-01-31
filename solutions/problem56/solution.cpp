#include "solution.hpp"
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> Solution::merge(std::vector<std::vector<int>> &intervals)
{
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b)
              { return a[0] < b[0]; });
    std::vector<std::vector<int>> ans;
    int currentLeftBound,currentRightBound,i;
    for (i = 0; i < intervals.size(); i++)
    {
        currentLeftBound = intervals[i][0];
        currentRightBound = intervals[i][1];
        while (i + 1 < intervals.size() && currentRightBound >= intervals[i + 1][0])
        {
            if (currentRightBound < intervals[i + 1][1])
                currentRightBound = intervals[i + 1][1];
            i++;
        }
        ans.push_back({currentLeftBound, currentRightBound});
    }
    return ans;
}
