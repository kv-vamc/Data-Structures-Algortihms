/*
LC#1461

Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.

Example 2:

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 

Example 3:

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.
*/
class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        int n = s.size();
        unordered_set<string> hash;

        for(int i = 0; i <= n - k; i++)
            hash.insert(s.substr(i, k));

        return hash.size() == (1 << k);
    }
};
