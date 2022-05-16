/*
LC#122

You are given an integer array prices where prices[i] is the price of a given stock on the ith day. On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day. Find and return the maximum profit you can achieve.

Example 1:
--------------------------------------------
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
--------------------------------------------
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
--------------------------------------------
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
*/
//Memoization
class Solution {
public:

    int dp[30001][2];

    int solve(int ind, int buy, vector<int>& prices, int n)
    {
        //bought stock and didn't sold till last day, then you won't make any profit.
        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit;

        if(buy)
            //you may buy it or you may not buy it.
            profit = max(-prices[ind] + solve(ind + 1, 0, prices, n), solve(ind + 1, 1, prices, n));
        else
            //you may sell it or you may not sell it.
            profit = max(prices[ind] + solve(ind + 1, 1, prices, n), solve(ind + 1, 0, prices, n));

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        memset(dp, -1, size(dp));

        return solve(0, 1, prices, n);    
    }
};

//Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;

                if(buy)
                    profit = max(-prices[i] + ahead[0], ahead[1]);
                else
                    profit = max(prices[i] + ahead[1], ahead[0]);

                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};

//Simple Intuitive approach
/*
suppose the first sequence is "a <= b <= c <= d", the profit is "d - a = (b - a) + (c - b) + (d - c)" without a doubt. And suppose another one is "a <= b >= b' <= c <= d", the profit is not difficult to be figured out as "(b - a) + (d - b')". So you just target at monotone sequences.
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) 
    {
        int ret = 0;
        for (size_t p = 1; p < prices.size(); ++p)
          //we are not interested in getting -ve profit so comparing with zero. In worst case zero will be the profit.
          ret += max(prices[p] - prices[p - 1], 0);    
        
        return ret;
    }
};
