#include "solution.hpp"
#include <vector>


int countOneBits(int n)
{
    int ans{0};
    while (n > 0)
    {
        ans += n & 0x1;
        n = n >> 1;
    };
    return ans;
}

std::vector<int> Solution::countBits(int n)
{
    std::vector<int> res(n + 1);
    for (int i = 0; i <= n; i++)
    {
        res[i] = countOneBits(i);
    }
    return res;
}
