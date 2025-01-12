class Solution {
public:
    bool search(vector<int>& nums, int t) {
        for(auto num : nums) {
            if(num==t) return true;
        }
        return false;
        
    }
};