class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        unordered_map<int,int> mp;
        for(auto interval : intervals){
            int start = interval[0];
            int end = interval[1] + 1;
            mp[start]++;
            mp[end]--;
        }
        vector<int> prefix(mp.size());
        for(auto [n, o] : mp){
            prefix.push_back(n);
        }
        sort(prefix.begin(), prefix.end());
        int pre = 0;
        int maxSum = 0;
        for(auto i : prefix){
            pre += mp[i];
            maxSum = max(maxSum, pre);
            
        }
        return maxSum;
    }
};