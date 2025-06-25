class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int currVal = nums[0];
        int currIdx = 1;
        for(int i = 1 ; i < n ; i++){
            if(currVal != nums[i]){
                nums[currIdx] = nums[i];
                currVal = nums[i];
                currIdx++;
            }
        }
        return currIdx;
    }
};