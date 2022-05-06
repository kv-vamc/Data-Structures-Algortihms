/*
LC#516

Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:
---------------------------------------------------------------
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
---------------------------------------------------------------
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
*/
class Solution {
public:

    int lcs(string text1, string text2, int m, int n)
    {
        int dp[m+1][n+1];
        
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0)
                    dp[i][j] = 0;
                else if(j == 0)
                    dp[i][j] = 0;
                
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }

    int longestPalindromeSubseq(string s)
    {
        int len = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        return lcs(s, rev, len, len);
    }
};
