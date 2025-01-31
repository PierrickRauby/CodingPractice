#include "solution.hpp"
#include <queue>

RecentCounter::RecentCounter()
{
}

int RecentCounter::ping(int t)
{
    int count{0};
    calls.push(t);
    while (1)
    {
        if (calls.front() < (t - 3000))
        {
            calls.pop();
        }
        else
        {
            return calls.size();
        }
    }
}
// Your implementation here
