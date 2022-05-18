/*
LC#309

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
-----------------------------------------
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
-----------------------------------------
Input: prices = [1]
Output: 0
*/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> ahead1(2, 0), ahead2(2, 0), curr(2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;

                if(buy)
                    profit = max(-prices[i] + ahead1[0], ahead1[1]);
                else
                    profit = max(prices[i] + ahead2[1], ahead1[0]);

                curr[buy] = profit;
            }
            ahead2 = ahead1;
            ahead1 = curr;
        }
        return ahead1[1];
    }
};
