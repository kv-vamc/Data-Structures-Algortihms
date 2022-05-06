/*
LC#583

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same. In one step, you can delete exactly one character in either string.

Example 1:
-----------------------------------------------------------
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:
-----------------------------------------------------------
Input: word1 = "leetcode", word2 = "etco"
Output: 4
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

    int minDistance(string word1, string word2)
    {
        int lcs_len, m = word1.size(), n = word2.size();
        lcs_len = lcs(word1, word2, m, n);
        return m + n - 2 * lcs_len;
    }
};
