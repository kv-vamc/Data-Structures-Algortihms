/*
LC#85

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size(), maxArea = 0;
        stack<int> st;

        for(int i = 0; i <= n; i++)
        {
            while(!st.empty() and (i == n or heights[st.top()] >= heights[i]))
            {
                int h = heights[st.top()], width;
                st.pop();

                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size(), maxRect = 0;
        vector<int> heights(cols, 0);

        for(int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            int area = largestRectangleArea(heights);

            maxRect = max(maxRect, area);

        }
        return maxRect;
    }
};
