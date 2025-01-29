#include "solution.hpp"
#include <map>
#include <string>
#include <climits>


int Solution::maxNumberOfBalloons(std::string text)
{
    std::map<char, int> ballons;
    std::map<char, int>::iterator it;
    // create a map to put the letters from ballons
    for (auto c : "balloon")
    {
        if (c != 0)
        {
            ballons[c] = 0;
        }
    }
    for (auto c : text)
    {
        it = ballons.find(c);
        if (it != ballons.end())
        { // c is in "b "
            it->second += 1;
        }
    }
    ballons['l'] = int(ballons['l'] / 2);
    ballons['o'] = int(ballons['o'] / 2);
    int min = INT_MAX;
    for (auto i : ballons)
    {
        if (i.second < min)
        {
            min = i.second;
        }
    }
    return min;
}
