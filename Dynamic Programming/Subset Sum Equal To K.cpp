/*
Code Studo.
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
*/
bool subsetSumToK(int n, int sum, vector<int> &arr)
{
    bool dp[n+1][sum+1];

    for(int i = 0; i <= n; i++)
        dp[i][0] = true;

    for(int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            if(arr[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][sum];
}
