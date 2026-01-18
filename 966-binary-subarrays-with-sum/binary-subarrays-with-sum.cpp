class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = 0, r = 0;
        int sum = 0;
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for(auto &it : nums){
            sum+=it;
            if(mp.count(sum - goal)) cnt+=mp[sum-goal];
            mp[sum]++;
        }
        return cnt;

    }
};