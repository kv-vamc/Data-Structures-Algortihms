/*
Code Studio

Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.
Note: The opponent is as clever as the user.

Let us understand the problem with few examples:  

5, 3, 7, 10 : The user collects maximum value as 15(10 + 5)
8, 15, 3, 7 : The user collects maximum value as 22(7 + 15)
*/
int optimalStrategyOfGame(vector<int> coins, int n)
{
    int dp[n][n];

    for(int i = 0; i < n-1; i++)
        dp[i][i+1] = std::max(coins[i], coins[i+1]);

    for(int gap = 3; gap < n; gap += 2)
    {
        for(int i = 0; i + gap < n; i++)
        {
            int j = i + gap;

            dp[i][j] = std::max(coins[i] + std::min(dp[i+2][j], dp[i+1][j-1]), coins[j] + std::min(dp[i+1][j-1], dp[i][j-2]));
        }
    }
    return dp[0][n-1];
}
