/*
LC#1048

You are given an array of words where each word consists of lowercase English letters. wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:
-----------------------------------------------------------------------
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Example 2:
-----------------------------------------------------------------------
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

Example 3:
-----------------------------------------------------------------------
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
*/
class Solution {
public:

    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }

    bool check(string &s1, string &s2)
    {
        int first = 0, second = 0, n = s1.size(), m = s2.size();

        if(n != m + 1) return false;

        while(first < n)
        {
            if(second < m and s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
                first++;
        }
        if(first == n and second == m)
            return true;
        else
            return false;
    }

    int longestStrChain(vector<string>& words)
    {
        int n = words.size(), maxi = 1, dp[1001];
        dp[0] = 1;

        sort(words.begin(), words.end(), comp);

        for(int i = 1; i < n; i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(check(words[i], words[j]) and 1 + dp[j] > dp[i])
                    dp[i] = 1 + dp[j];
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
