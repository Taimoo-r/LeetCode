class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int left = 0;
        int right = n - 1;
        while(left < right){
            maxArea = max(min(height[left], height[right]) * (right - left), maxArea);
            if(height[left] <= height[right]) left++;
            else right--;
        }
        return maxArea;
    }
};