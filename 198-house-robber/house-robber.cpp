class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> v(nums.size() + 1, -1);
        return helper(nums, 0, v);
    }
    int helper(vector<int>& nums, int i,  vector<int> &v){
        if(i >= nums.size()) return 0;
        if(v[i]!=-1) return v[i];
        int steal = nums[i] + helper(nums, i + 2, v);
        int skip = helper(nums, i + 1, v);
        v[i] = max(steal, skip);
        return v[i];
    }
};