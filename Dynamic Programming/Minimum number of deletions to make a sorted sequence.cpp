/*
GFG

Given an array arr of size N, the task is to remove or delete the minimum number of elements from the array so that when the remaining elements are placed in the same sequence order form an increasing sorted sequence.

Example 1:
-------------------------------------------------------------
Input: N = 5, arr[] = {5, 6, 1, 7, 4}
Output: 2
Explanation: Removing 1 and 4 leaves the remaining sequence order as 5 6 7 which is a sorted sequence.

Example 2:
-------------------------------------------------------------
Input: N = 3, arr[] = {1, 1, 1}
Output: 2
Explanation: Remove 2 1's
*/
Class Solution{
public:
    int minDeletions(int nums[], int n)
    {
        int dp[n], maxi = 1;

        for(int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i] and 1 + dp[j] > dp[i])
                    dp[i] = 1 + dp[j];
            }
            maxi = max(maxi, dp[i]);
        }
        return n - maxi;
    }
};
