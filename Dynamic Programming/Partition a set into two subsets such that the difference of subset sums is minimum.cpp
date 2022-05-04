/*
Code Studio.

You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
*/
int subsetSumToK(int n, int sum, vector<int> &arr)
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

    for (int i = sum/2 ; i >= 0; ++i)
    {
        if(dp[n][i] == true)
            return abs((sum - (2 * i)));
    }
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return subsetSumToK(n, sum, arr);
}
