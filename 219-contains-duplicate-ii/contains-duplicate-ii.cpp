class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        int n = nums.size();
        int i = 0;
        for(int j = 0 ; j < n ; j++){
            if(j - i > k) s.erase(nums[i++]);
            if(s.count(nums[j])) return true;
            s.insert(nums[j]);
        }
        return false;
    }
};