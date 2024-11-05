class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_p = nums[0];
        int min_p = nums[0];
        int n = nums.size();
        int res = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(nums[i] < 0)
                swap(min_p, max_p);
            max_p = max(nums[i], max_p*nums[i]);
            min_p = min(nums[i], min_p*nums[i]);
            res = max(res, max_p);
        }
        return res;
        
    }
};