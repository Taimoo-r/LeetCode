class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currP = INT_MIN;
        int maxP = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            currP = 1;
            for(int j = i ; j < n ; j++){
                currP*=nums[j];
                maxP = max(currP, maxP);
            }
        }
        return maxP;
    }
};