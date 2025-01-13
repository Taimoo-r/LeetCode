class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 0, h = n - 1;
        while(l <= h){
            int m = l + (h - l)/2;

            if(nums[m] == t) return m;

            else if(nums[m] >= nums[l]){  // kia ye left sorted hai?
                if(nums[l] <= t && nums[m] >= t) h = m - 1;
                else l = m + 1;
            }
            else if(nums[m] <= nums[h]){
                if(nums[h] >= t && nums[m] <= t) l = m + 1;
                else h = m - 1;
            }
        }
        return -1;
    }
};