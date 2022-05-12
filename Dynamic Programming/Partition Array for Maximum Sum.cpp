/*
LC#1043

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray. Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
----------------------------------------------------------------------
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Example 2:
----------------------------------------------------------------------
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

Example 3:
----------------------------------------------------------------------
Input: arr = [1], k = 1
Output: 1
*/
class Solution {
public:

    int dp[501];

    int solve(vector<int>& arr, int ind, int k)
    {
        int n = arr.size();

        //stop when index cross last element.
        if(ind == n) return 0;

        if(dp[ind] != -1)
            return dp[ind];

        int len = 0, maxi = 0, ans = 0;

        for(int j = ind; j < min(ind + k, n); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);

            int sum = len * maxi + solve(arr, j + 1, k);

            ans = max(sum, ans);
        }
        return dp[ind] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        memset(dp, -1, sizeof(dp));

        return solve(arr, 0, k);
    }
};
