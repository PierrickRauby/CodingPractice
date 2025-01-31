#include "solution.hpp"
#include <vector>

void Solution::merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    std::vector<int> nums1Copy(nums1.begin(), nums1.begin() + m);
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < m + n; i++)
    {
        if (p2 >= n || (p1 < m && nums1Copy[p1] < nums2[p2]))
        {
            nums1[i] = nums1Copy[p1];
            p1++;
        }
        else
        {
            nums1[i] = nums2[p2];
            p2++;
        }
    }
}
