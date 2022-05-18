/*
lC#188

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k. Find the maximum profit you can achieve. You may complete at most k transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
------------------------------------------
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
------------------------------------------
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size(), profit = 0;
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0)), curr(2, vector<int>(k + 1, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int trans = 1; trans <= k; trans++)
                {
                    if(buy)
                        profit = max(-prices[i] + ahead[0][trans], ahead[1][trans]);
                    else
                        profit = max(prices[i] + ahead[1][trans - 1], ahead[0][trans]);

                    curr[buy][trans] = profit;  
                }
            }
            ahead = curr;
        }
        return ahead[1][k];
    }
};
