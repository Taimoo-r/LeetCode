class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max = INT_MIN;
        while(i<j){
            if(height[i]<height[j]){
                if(max < height[i]*(j-i))
                max = height[i]*(j-i);
                i++;
            }
            else if(height[i]>=height[j]){
                if(max < height[j]*(j-i))
                max = height[j]*(j-i);
                j--;
            }
        }
        return max;
    }
};