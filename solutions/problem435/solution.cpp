#include "solution.hpp"
#include <vector>
#include <climits>
#include <algorithm>

int Solution::eraseOverlapIntervals(std::vector<std::vector<int>> &intervals)
{
    // first sort intervals
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int> &a, const std::vector<int> &b)
              {
                  return a[0] < b[0];
              });
    int currentRightBound = intervals[0][1];
    int ans = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (currentRightBound <=
            intervals[i][0])
        { // the current interval does not overlaps with the
          // next one
            currentRightBound = intervals[i][1];
        }
        else
        {
            currentRightBound =
                std::min(intervals[i][1], currentRightBound);
            ans += 1;
        }
    }
    return ans;
}
