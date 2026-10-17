class Solution {
public:
    int lower(vector<int>& nums, int t){
        int st = 0, en = nums.size()-1;
        int ans = -1;
        while(st <= en){
            int md = st + (en - st)/2;
            if(nums[md] > t) en = md -1;
            else if(nums[md] < t) st = md+1;
            else {
                ans = md;
                en = md - 1;
            }
        }
        return ans;
    }
    int higher(vector<int>& nums, int t){
        int st = 0, en = nums.size()-1;
        int ans = -1;
        while(st <= en){
            int md = st + (en - st)/2;
            if(nums[md] > t) en = md -1;
            else if(nums[md] < t) st = md+1;
            else {
                ans = md;
                st = md+ 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int t) {
        return {lower(nums, t), higher(nums, t)};
    }
};