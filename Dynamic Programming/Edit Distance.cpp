/*
LC#72

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2. You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:
-----------------------------------------------------------------
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
-----------------------------------------------------------------
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
#include <algorithm>
class Solution {
public:
    /* Recursive
    int editDistance(string word1, string word2, int m, int n)
    {
        if(m == 0) return n;
        if(n == 0) return m;
        
        if(word1[m-1] == word2[n-1])
            return editDistance(word1, word2, m-1, n-1);
        else
            return 1 + std::min(editDistance(word1, word2, m, n-1), std::min(editDistance(word1, word2, m-1, n), editDistance(word1, word2, m-1, n-1)));
        
    }*/
    
    int editDistance(string word1, string word2, int m, int n)
    {
        int dp[m+1][n+1];
        
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0) dp[i][j] = j;
                else if(j == 0) dp[i][j] = i;
                
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + std::min(dp[i][j-1], std::min(dp[i-1][j], dp[i-1][j-1]));        
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2)
    {
        return editDistance(word1, word2, word1.length(), word2.length());
    }
};
