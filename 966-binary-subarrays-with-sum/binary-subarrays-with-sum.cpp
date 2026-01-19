class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = 0, r = 0;
        int sum = 0;
        int n = nums.size();
        int cnt = 0;
        int z = 0;
        while(r < n){
            sum+=nums[r];
            while(l < r && (nums[l] == 0 || sum > goal) ){
                if(nums[l] == 0) z++;
                else z = 0;
                sum-=nums[l];
                l++;
            }
            if(sum == goal) cnt+=1+z;
            r++;
        }
        return cnt;
    }
};