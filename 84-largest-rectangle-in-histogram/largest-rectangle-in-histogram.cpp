class Solution {
public:
    vector<int> nextSmallerRight(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n, n);  // Default right boundary is 'n' (out of bounds)
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) 
                st.pop();
            if (!st.empty()) right[i] = st.top();  // Store the index
            st.push(i);
        }
        return right;
    }

    vector<int> nextSmallerLeft(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1);  // Default left boundary is '-1' (out of bounds)
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) 
                st.pop();
            if (!st.empty()) left[i] = st.top();  // Store the index
            st.push(i);
        }
        return left;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = nextSmallerLeft(heights);
        vector<int> right = nextSmallerRight(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;  // Width of the rectangle
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
};
