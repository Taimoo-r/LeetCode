class Solution {
public:
    int search(vector<int>& nums, int t) {
        int st = 0, en = nums.size() - 1;
        int ans = -1;
        while(st <= en){
            int md = st + (en - st) / 2;
            if(nums[md] == t) return md;
            else if(nums[st] <= nums[md]){
                if(t >= nums[st] && t <= nums[md])
                    en = md-1;
                else st = md+1;
            }
            else if(nums[md] <= nums[en]){
                if(t >= nums[md] && t <= nums[en])
                    st = md+1;
                else en = md-1;
            } 
        }
        return -1;
    }
};