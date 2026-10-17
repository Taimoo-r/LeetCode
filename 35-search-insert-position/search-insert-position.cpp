class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        int st = 0, en = nums.size()-1;
        int ans = nums.size();
        while(st <= en){
            int md = st + (en-st)/2;
            if(nums[md] < x) st = md+1;
            else if(nums[md] >= x){
                ans = md;
                en = md -1;
            }
        }
        return ans;
    }
};