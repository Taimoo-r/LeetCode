class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return all(nums, k)-all(nums, k-1);
    }
    int all(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        for(int l = 0, r = 0 ; r < n ; r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                if(mp[nums[l]] == 1) mp.erase(nums[l]);
                else mp[nums[l]]--;
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};