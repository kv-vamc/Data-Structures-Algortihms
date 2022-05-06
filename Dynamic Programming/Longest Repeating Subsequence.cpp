/*
Code Studio

You are given a string ‘st’, Your task is to find the length of the longest repeating subsequence such that two subsequences don’t have the same character at the same position.

For Example :
The given string st = AABCBDC.
As you can see there are two repeating longest subsequences “ABC” with the same character but different position. Therefore the required answer is ‘3’ as the length of “ABC” is 3.
*/
int longestRepeatingSubsequence(string st, int n)
{
    int dp[n+1][n+1];
        
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0)
                    dp[i][j] = 0;
                else if(j == 0)
                    dp[i][j] = 0;
                
                else if(st[i-1] == st[j-1] && i != j)
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
}
