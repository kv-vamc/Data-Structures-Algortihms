/*
LC#887

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n. You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:
-------------------------------------------------------------
Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

Example 2:
-------------------------------------------------------------
Input: k = 2, n = 6
Output: 3

Example 3:
-------------------------------------------------------------
Input: k = 3, n = 14
Output: 4
*/
class Solution {
public:

    int solve(int eggs, int floors, vector<vector<int>>& dp)
    {
        if(floors == 0 or floors == 1)
            return floors;

        if(eggs == 1)
            return floors;

        if(dp[eggs][floors] != -1)
            return dp[eggs][floors];

        int low = 1, high = floors, mid, left, right, temp, result = INT_MAX;

        while(low <= high)
        {
            mid = (low + high)/2;

            if(dp[eggs-1][mid-1] != -1)
                left = dp[eggs-1][mid-1];
            else
            {
                left = solve(eggs - 1, mid - 1, dp);
                dp[eggs-1][mid-1] = left;
            }
            
            if(dp[eggs][floors-mid] != -1)
                right = dp[eggs][floors-mid];
            else
            {
                right = solve(eggs, floors - mid, dp);
                dp[eggs][floors-mid] = right;
            }

            temp =  1 + max(left, right);

            result = min(result, temp);

            if(left < right)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return dp[eggs][floors] = result;
    }

    int superEggDrop(int eggs, int floors)
    {
        vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, -1));

        return solve(eggs, floors, dp);
    }
};
