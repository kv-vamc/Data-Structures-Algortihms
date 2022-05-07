/*
Code Studio
*/
int dp[102][102];

int solve(vector<int> &arr, int i, int j)
{
    if (i == j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int res = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int temp = solve(arr, i, k)
                    + solve(arr, k + 1, j)
                    + arr[i - 1] * arr[k] * arr[j];

        res = std::min(res, temp);
    }
    return dp[i][j] = res;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    int i = 1, j = N - 1;

    for (int i = 0; i < 102; ++i)
        for (int j = 0; j < 102; ++j)
            dp[i][j] = -1;

    return solve(arr, i, j);
}
