class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 0, h = n - 1;
        while(l <= h){
            int m = l + (h - l)/2;
            if(t==nums[m]) return true;
            else if(nums[l]==nums[m] && nums[m]==nums[h]){
                l++;
                h--;
            }
            else if(nums[l] <= nums[m]){ // ye wala left sara sorted hai
                if(nums[l] <= t && nums[m] >= t) // aab ye check kro kay kia t isme hai?
                    h = m - 1; // agr hai to just hum left-to-mid tk apni search krden ge
                else    // agr nhi hai
                    l = m + 1; // means wo phr mid-to-right mein hai
            }
            else if(nums[h] >= nums[m] ){
                if(nums[h] >= t && nums[m] <= t)
                    l = m + 1;
                else
                    h = m - 1;
            }
        }
        return false;
    }
};