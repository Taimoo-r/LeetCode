class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int prefixSum = 0;
        int cnt = 0;
        mp[0] = 1;

        for(auto &n : nums){
            prefixSum+=n;

            if(mp.count(prefixSum - k)){
                cnt+=mp[prefixSum-k];
            }
                mp[prefixSum]++;

        }
        return cnt;
        
    }
};