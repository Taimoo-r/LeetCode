class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int currentMax = 0;
        int maxC = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]==1)
                currentMax++;
            else{
                maxC = max(maxC,currentMax);
                currentMax = 0;
            }
        }
        maxC = max(maxC,currentMax);
        return maxC;
    }
};