class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max_area = 0;

        while (i < j) {
            int width = j - i;
            int current_height = min(height[i], height[j]);
            int current_area = width * current_height;
            max_area = max(max_area, current_area);

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return max_area;
    }
};