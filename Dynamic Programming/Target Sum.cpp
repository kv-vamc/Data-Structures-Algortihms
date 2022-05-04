/*
LC#494
You are given an integer array nums and an integer target. You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers. For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
----------------------------------------------------------------
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
----------------------------------------------------------------
Input: nums = [1], target = 1
Output: 1
*/
class Solution {
public:

    int subsetSumToK(int n, int sum, vector<int> &arr)
    {
        int dp[n+1][sum+1], count = 0;

        dp[0][0] = 1;

        for(int i = 1; i <= sum; i++)
            dp[0][i] = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
        }
        return dp[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
            int sum = 0, new_target = abs(target);
            for(int i = 0; i < nums.size(); i++)
                sum += nums[i];
            if(sum < new_target || (sum + new_target)%2 != 0) return 0;

            return subsetSumToK(nums.size(), (new_target + sum)/2, nums);
    }
};
