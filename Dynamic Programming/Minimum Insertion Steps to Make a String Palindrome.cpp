/*
LC#1312

Given a string s. In one step you can insert any character at any index of the string. Return the minimum number of steps to make s palindrome. A Palindrome String is one that reads the same backward as well as forward.

Example 1:
-------------------------------------------
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.

Example 2:
-------------------------------------------
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:
-------------------------------------------
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
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

    int minInsertions(string s)
    {
        int len = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        return len - lcs(s, rev, len, len);
    }
};
