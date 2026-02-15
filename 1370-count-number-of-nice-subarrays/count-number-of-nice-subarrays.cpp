class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return all(nums, k)-all(nums, k-1);
    } 
    int all(vector<int>& nums, int k){
        int n = nums.size();
        int odd = 0;
        int ans = 0;
        for(int l = 0, r = 0 ; r < n ; r++){
            odd+=(nums[r]%2);
            while(odd > k){
                odd-=(nums[l]%2);
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};