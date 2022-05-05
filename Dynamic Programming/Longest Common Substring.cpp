/*
Code Studio
You have been given two strings 'STR1' and 'STR2'. You have to find the length of the longest common substring.
A string “s1” is a substring of another string “s2” if “s2” contains the same characters as in “s1”, in the same order and in continuous fashion also.

For Example :
If 'STR1' = “abcjklp” and 'STR2' = “acjkp”  then the output will be 3.
Explanation: The longest common substring is “cjk” which is of length 3.

*/
int lcs(string &str1, string &str2)
{
    int m = str1.size(), n = str2.size(), dp[m+1][n+1], substr_len = 0;

    for (int i = 0; i <= m; ++i)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                substr_len = std::max(substr_len, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return substr_len;
}
