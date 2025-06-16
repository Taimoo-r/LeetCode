class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto &it : nums){
            if(mp.count(it)) return true;
            mp.insert(it);
        }
        return false;
        
    }
};