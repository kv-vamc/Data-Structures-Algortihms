/*
LC#64

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for(int j = 0; j < n; j++)
            {
                int up = INT_MAX, left = INT_MAX;

                if(i == 0 && j == 0)
                    cur[j] = grid[0][0];
                else
                {
                    if(i > 0) up = grid[i][j] + prev[j];
                    if(j > 0) left = grid[i][j] + cur[j-1];
                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};
