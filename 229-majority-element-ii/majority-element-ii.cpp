class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int more = nums.size()/3;
        set<int> st;
        map<int, int> mp;
        vector<int> v;
        for(auto &it : nums) {
            mp[it]++;
            if(mp[it] > more && !st.count(it)) {
                v.push_back(it);
                st.insert(it);
            }
        }

        return v;
    }
};