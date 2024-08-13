class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int count = 0;
        for(auto t : s){
            nums[count++] = t;
        }
        return count;

        
    }
};