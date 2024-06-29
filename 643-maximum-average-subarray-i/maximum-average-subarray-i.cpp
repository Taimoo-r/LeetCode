class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()<k)
        return 0.0;
        long currSum=0;
        long maxSum;
        for(int i = 0; i < k ; i++){
            currSum+=nums[i];
        }
        maxSum = currSum;
        for(int i = k ; i < nums.size();i++){
            currSum += nums[i] - nums[i-k];
            
            maxSum = max(currSum,maxSum);
        }
        return static_cast<double>(maxSum)/k;
    }
};