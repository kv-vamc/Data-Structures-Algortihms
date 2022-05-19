/*
LC#84

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
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
};
