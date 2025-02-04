class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi;
        int currSum = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(nums[i-1] < nums[i]){
                currSum+=nums[i];
            }
            else{
                maxi = max(maxi, currSum);
                currSum = nums[i];
            }
        }
        maxi = max(maxi, currSum);
        return maxi;
    }
};