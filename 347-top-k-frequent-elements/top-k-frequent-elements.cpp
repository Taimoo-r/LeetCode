class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        vector<vector<int>> res;
        for(auto it : mp){
            res.push_back({it.second,it.first});
        }
        vector<int> ans;
        sort(res.begin(),res.end());
        for(int i = res.size()-1; k ; i--,k--){
            ans.push_back(res[i][1]);
        }
        return ans;
    }
};
