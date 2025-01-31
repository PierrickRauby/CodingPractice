#include "solution.hpp"
#include <vector>

void Solution::reverseString(std::vector<char> &s)
{
    int front, back;
    front = 0;
    back = s.size() - 1;
    char tmp;
    while (front < back)
    {
        tmp = s[front];
        s[front] = s[back];
        s[back] = tmp;
        front++;
        back--;
    }
}
