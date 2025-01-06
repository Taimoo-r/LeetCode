class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int more = nums.size()/3;
        map<int, int> mp;
        for(auto &it : nums) mp[it]++;

        vector<int> v;

        for(auto [a, b] : mp){
            if(b>more) v.push_back(a);
        }
        return v;
    }
};