/*
LC#368

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:
----------------------------------------
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
----------------------------------------
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
*/
class Solution {
public:

    int dp[1002], hash[1002];

    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int n = nums.size(), maxi = 1, last_ind = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++)
        {
            hash[i] = i;
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0 and 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j]; 
                    //hash is intuitively storing jth element, which is considered in the answer.
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                //here last_ind stores the index of last element of answer.
                last_ind = i;
            }
        }

        vector<int> subset;
        //pushing last element which is part of answer.
        subset.push_back(nums[last_ind]);

        //track back the elements which are part of final answer using hash array.
        while(hash[last_ind] != last_ind)
        {
            last_ind = hash[last_ind];
            subset.push_back(nums[last_ind]);
        }
        return subset;
    }
};
