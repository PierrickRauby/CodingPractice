#include "solution.hpp"
#include <iostream>
#include <vector>

bool Solution::canPlaceFlowers(std::vector<int> &flowerbed, int n)
{
    for (int i = 0; i < flowerbed.size(); i++)
    {
        std::cout << "i:" << i << "floweredbed: " << flowerbed[i] << std::endl;
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
        {
            n--;
            flowerbed[i] = 1;
            std::cout << " planting" << std::endl;
        }
    }
    if (n <= 0)
    {
        return true;
    }

    return false;
}
