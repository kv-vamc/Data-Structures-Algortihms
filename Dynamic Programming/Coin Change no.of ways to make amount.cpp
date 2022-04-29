/*
LC#518

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money. 
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0. 
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:
----------------------------------------------------------------
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
----------------------------------------------------------------
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
----------------------------------------------------------------
Input: amount = 10, coins = [10]
Output: 1
*/
/* Recursive Solution

int change(int amount, int* coins, int coinsSize)
{
    if(amount == 0) return 1;
    
    if(coinsSize == 0) return 0;
    
    int res = change(amount, coins, coinsSize - 1);
    
    if(coins[coinsSize - 1] <= amount)
        res += change(amount - coins[coinsSize - 1], coins, coinsSize);
    
    return res;
}*/

//Dp Approach

int change(int amount, int* coins, int coinsSize)
{
    int dp[amount+1][coinsSize+1];
    
    for(int i = 0; i <= coinsSize; i++)
        dp[0][i] = 1;
    
    for(int i = 1; i <= amount; i++)
        dp[i][0] = 0;
    
    for(int i = 1; i <= amount; i++)
    {
        for(int j = 1; j <= coinsSize; j++)
        {
            dp[i][j] = dp[i][j-1];
            
            if(coins[j-1] <= i)
                dp[i][j] += dp[i-coins[j-1]][j];
        }
    }
    
    return dp[amount][coinsSize];
}
