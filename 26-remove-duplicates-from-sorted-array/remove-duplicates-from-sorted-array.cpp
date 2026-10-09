class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int v = nums[0];
        int idx = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(v!=nums[i]){
                v = nums[i];
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx;
    }
};