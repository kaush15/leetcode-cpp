// Problem: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Approach: Keep the track of best buy with the max profit
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy=prices[0];
        int maxprofit=0;
        for(int i=1;i<prices.size();i++){
            if(bestbuy >prices[i]){
                bestbuy=prices[i];
            }
            maxprofit= max(maxprofit,prices[i]-bestbuy);
        }
        return maxprofit;
    }
};
