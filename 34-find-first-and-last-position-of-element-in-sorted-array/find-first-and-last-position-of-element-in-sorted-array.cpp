class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        vector<int> ans(2, -1);
        int st = 0, en = nums.size() - 1;
        while(st <= en){
            int md = st + (en - st)/2;
            if(nums[md]==t){
                while(md >= 0 && nums[md]==t)
                    md--;
                md++;
                ans[0] = md;
                while(md < nums.size() && nums[md] == t)
                    md++;
                ans[1] = md - 1;
                return ans;
            }
            else if(nums[md] > t)
                en = md - 1;
            else
                st = md + 1;
        }
        return ans;
        
    }
};