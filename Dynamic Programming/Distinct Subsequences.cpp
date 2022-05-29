/*
LC#115

Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:
--------------------------------------
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit

Example 2:
--------------------------------------
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
*/
class Solution {
public:
    int numDistinct(string s1, string s2)
    {  
        int n = s1.size(), m = s2.size();
        vector<double> prev(m + 1, 0);
        prev[0] = 1;

        for(int i = 1; i <= n; i++)
        {
            for(int j = m; j >= 1; j--)
            {
                if(s1[i-1] == s2[j-1])
                    prev[j] = prev[j-1] + prev[j];
            }
        }
        return (int)prev[m];
    }
};
