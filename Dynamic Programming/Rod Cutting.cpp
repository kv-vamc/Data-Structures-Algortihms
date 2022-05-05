/*
Code Studio.

Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.
*/
int cutRod(vector<int> &price, int n)
{
    int len[n], dp[n+1][n+1];

    for(int i = 0; i < n; i++)
        len[i] = i + 1;

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 or j == 0)
                dp[i][j] = 0;
            else if(len[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = std::max(dp[i-1][j], price[i-1] + dp[i][j-len[i-1]]);
        }
    }
    return dp[n][n];
}
