/*
LC#673

Given an integer array nums, return the number of longest increasing subsequences. Notice that the sequence has to be strictly increasing.

Example 1:
-------------------------------------------
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
-------------------------------------------
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n = nums.size(), dp[n], count[n], maxi = 1, lis_count = 0;

        for(int i = 0; i < n; i++)
        {
            dp[i] = 1;
            count[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i] and 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }
                else if(nums[j] < nums[i] and 1 + dp[j] == dp[i])
                    count[i] += count[j];
            }
            maxi = max(maxi, dp[i]);
        }
        //To count #LIS.
        for(int i = 0; i < n; i++)
        {
            if(maxi == dp[i])
                lis_count += count[i];
        }
        return lis_count;
    }
};
