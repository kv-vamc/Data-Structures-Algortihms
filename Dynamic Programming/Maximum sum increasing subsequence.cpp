/*
GFG

Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order i.e. increasing subsequence. 

Example 1:
----------------------------------------------------------
Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100}

Example 2:
----------------------------------------------------------
Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a increasing sequence is obtained from {1, 2, 3}
*/
Class Solution{
  public:
    int maxSumIS(int nums[], int n)
    {
        int sum[n], maxi = 0;

        for(int i = 0; i < n; i++)
        {
            sum[i] = nums[i];
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i] and sum[j] + nums[i] > sum[i])
                    sum[i] = sum[j] + nums[i];
            }
            maxi = max(maxi, sum[i]);
        }
        return maxi;
    }
};
