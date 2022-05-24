/*
LC#213

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
---------------------------------
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
---------------------------------
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
---------------------------------
Input: nums = [1,2,3]
Output: 3
*/
class Solution {
public:
    int robber(vector<int>& nums, int l, int r)
    {
        int n = nums.size(), prev1 = nums[l], prev2 = 0, take, not_take, cur;

        for(int i = l + 1; i <= r; i++)
        {
            take = nums[i];
            if(i > 1)
                take += prev2;

            not_take = prev1;

            cur = max(take, not_take);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1; 
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1) return  nums[0];

        int first, sec;
        first = robber(nums, 1, n - 1);
        sec = robber(nums, 0, n - 2);

        return max(first, sec);
    }
};
