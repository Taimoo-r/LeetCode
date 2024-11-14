class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> mp;
        vector<int> ans;
        for(auto &it : nums1)
            mp[it] = false;
        for(auto &it : nums2)
            if(mp.count(it) && mp[it] == false)  {
                ans.push_back(it);
                mp[it] = true;
            }
        return ans;
    }
};