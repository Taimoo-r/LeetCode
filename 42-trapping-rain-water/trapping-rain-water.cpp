class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; // Monotonic decreasing stack (stores indices)
        int water = 0;
        int n = height.size();

        for (int i = 0; i < n; i++) {
            // If the current height is greater than the stack’s top, process trapped water
            while (!st.empty() && height[i] > height[st.top()]) {
                int bottom = st.top();
                st.pop();
                
                if (st.empty()) break; // No left boundary

                int left = st.top();  // Left boundary index
                int width = i - left - 1;  // Distance between left and right boundary
                int bounded_height = min(height[left], height[i]) - height[bottom]; // Water height
                
                water += width * bounded_height;
            }

            st.push(i);
        }
        return water;
    }
};
