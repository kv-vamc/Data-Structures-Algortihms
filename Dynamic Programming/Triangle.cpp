/*
LC#120

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:
-----------------------------------------------------------------------
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
-----------------------------------------------------------------------
Input: triangle = [[-10]]
Output: -10
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int m = triangle.size();
        vector<int> front(m, 0);

        for(int i = 0; i < m; i++)
            front[i] = triangle[m-1][i];

        for(int i = m - 2; i >= 0; i--)
        {
            vector<int> cur(m, 0);
            for(int j = i; j >= 0 ; j--)
            {
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j+1];
                cur[j] = min(down, diag);
            }
            front = cur;
        }
        return front[0];
    }
};
