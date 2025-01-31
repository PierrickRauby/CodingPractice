#include "solution.hpp"
#include <vector>
#include <climits>

int Solution::maxProfit(std::vector<int> &prices)
{
        int minPrice=INT_MAX;
    int maxProfit=0;
    for(int i=0;i<prices.size();i++){
       if(prices[i]<minPrice) {
        minPrice=prices[i];
       }else if(maxProfit<prices[i]-minPrice){
        maxProfit=prices[i]-minPrice;
        
       }
    }
    return maxProfit;
}
