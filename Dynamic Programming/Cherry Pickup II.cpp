/*
LC#1463

You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> prev(m, vector<int>(m, 0));

        //base case, when robos reaches last row of grid.
        for(int j1 = 0; j1 < m; j1++)
        {
            for(int j2 = 0; j2 < m; j2++)
            {
                //if both robos reaches same cell.
                if(j1 == j2)
                    prev[j1][j2] = grid[n-1][j1];
                else
                    prev[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }   
        }

        for(int i = n - 2; i >= 0; i--)
        {
            vector<vector<int>> cur(m, vector<int>(m, 0));
            for(int j1 = 0; j1 < m; j1++)
            {
                for(int j2 = 0; j2 < m; j2++)
                {
                    int maxi = INT_MIN;

                    //all possible choices.
                    for(int dj1 = -1; dj1 <= +1; dj1++)
                    {
                        for(int dj2 = -1; dj2 <= +1; dj2++)
                        {
                            int value;

                            //if both robos reaches same cell.
                            if(j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            //handling out of bounds case, when robos go out of grid.
                            if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                                value += prev[j1 + dj1][j2 + dj2];
                            else
                                value += -1e9;

                            maxi = max(maxi, value);
                        } 
                    }
                    cur[j1][j2] = maxi;
                }
            }
            prev = cur;
        }
        return prev[0][m - 1];    
    }
};
