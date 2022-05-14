/*
GFG

Given an array of positive integers. Find the maximum length of Bitonic subsequence.  A subsequence of array is called Bitonic if it is first increasing, then decreasing.

Example 1:
---------------------------------------------
Input: nums = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is increasing and the sequence {3, 2} is  decreasing so merging both we will get length 5.

Example 2:
---------------------------------------------
Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence  {1, 2, 10, 4, 2, 1} has length 6.
*/
Class Solution{
  public:
	int LongestBitonicSequence(vector<int>& nums)
    {
        int n = nums.size(), dp1[n], dp2[n], lbs_len = 1;

        for(int i = 0; i < n; i++)
        {
            dp1[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i] and 1 + dp1[j] > dp1[i])
                    dp1[i] = 1 + dp1[j];
            }
        }

        for(int i = n - 1; i >= 0; i--)
        {
            dp2[i] = 1;
            for(int j = n - 1; j > i; j--)
            {
                if(nums[j] < nums[i] and 1 + dp2[j] > dp2[i])
                    dp2[i] = 1 + dp2[j];
            }
        }

        for(int i = 0; i < n; i++)
            lbs_len = max(lbs_len, dp1[i] + dp2[i] - 1);

        return lbs_len;
    }
};
