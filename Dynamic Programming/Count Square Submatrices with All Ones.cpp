/*
LC#1277

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size(), dp[rows][cols], count = 0;

        for(int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = matrix[i][j];
                else if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));

                count += dp[i][j];
            }
        }
        return count;
    }
};
