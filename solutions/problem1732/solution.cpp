#include "solution.hpp"
#include <vector>

int Solution::largestAltitude(std::vector<int> &gain)
{
    int maxAltitude = 0;     // starting at 0
    int currentAltitude = 0; // starting at 0
                             // i=0 biker as completed the first segment
    for (int i = 0; i < gain.size(); i++)
    {
        currentAltitude += gain[i];
        if (currentAltitude > maxAltitude)
        {
            maxAltitude = currentAltitude;
        }
    }
    return maxAltitude;
}

// Your implementation here
