/*
LC#300

Given an integer array nums, return the length of the longest strictly increasing subsequence. A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:
---------------------------------------------------------
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
---------------------------------------------------------
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
---------------------------------------------------------
Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/
class Solution {
public:
    
    int ceilIndex(vector<int>& tail, int l, int r, int key)
    {
        int mid;
        
        while(r > l)
        {
            mid = l + (r - l)/2;
            if(tail[mid] >= key)
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
    
    int lengthOfLIS(vector<int>& nums)
    {
        if(nums.size() == 0) return 0;
        
        vector<int> tail;
        tail.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > tail[tail.size()-1])
                tail.push_back(nums[i]);
             else
                 tail[ceilIndex(tail, 0, tail.size(), nums[i])] = nums[i];
        }
        return tail.size();
    }
};
