class Solution {
public:
    bool check(vector<int>& nums) {
        int inc = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > nums[(i+1)%nums.size()])
                inc++;
            if(inc>=2) return false;
        }
        return true;
    }
};