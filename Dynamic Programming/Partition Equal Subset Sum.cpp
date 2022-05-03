/*
LC#416

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:
-----------------------------------------------------------
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
-----------------------------------------------------------
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/
class Solution {
public:

    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        bool dp[n+1][k+1];

        for(int i = 0; i <= n; i++)
            dp[i][0] = true;

        for(int i = 1; i <= k; i++)
            dp[0][i] = false;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        return dp[n][k];
    }

    bool canPartition(vector<int>& nums)
    {
        int sum = 0, n = nums.size();

        for(int i = 0; i < n; i++)
            sum += nums[i];
        if(sum%2 != 0)
            return false;
        else
            return subsetSumToK(n, sum/2, nums);
    }
};
