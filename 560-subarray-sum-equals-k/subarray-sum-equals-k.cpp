class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pre=0, count=0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i = 0 ; i < n ; i++){
            pre += nums[i];
            int remove = pre - k;
            count += mp[remove];
            mp[pre]++;
        }
        return count;
    }
};