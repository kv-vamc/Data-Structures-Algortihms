/*
LC#931

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        vector<int> prev(n, 0);

        for(int j = 0; j < n; j++)
            prev[j] = matrix[n-1][j];

        for(int i = n - 2; i >= 0; i--)
        {
            vector<int> cur(n, 0);
            for(int j = 0; j < n; j++)
            {
                int up, rd, ld;

                up = matrix[i][j] + prev[j];
                rd = matrix[i][j]; 
                if(j + 1 < n)
                    rd += prev[j+1];
                else
                    rd += 1e9;
                ld = matrix[i][j];
                if(j > 0)
                    ld += prev[j-1];
                else
                    ld += 1e9;

                cur[j] = min(up, min(rd, ld));
            }
            prev = cur;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
