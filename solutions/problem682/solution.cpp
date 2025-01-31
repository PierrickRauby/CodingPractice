#include "solution.hpp"
#include <string>
#include <vector>
#include <stack>

int Solution::calPoints(std::vector<std::string> &operations)
{
    std::vector<int> out;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "C")
        {
            out.pop_back();
        }
        else if (operations[i] == "D")
        {
            int above = out.back();

            out.push_back(2 * above);
        }
        else if (operations[i] == "+")
        {
            int above = out.back();
            int above1 = out[out.size() - 2];
            out.push_back(above + above1);
        }
        else
        {
            out.push_back(stoi(operations[i]));
        }
    }
    int sum = 0;
    for (int i = 0; i < out.size(); i++)
    {
        sum += out[i];
    }
    return sum;
}
