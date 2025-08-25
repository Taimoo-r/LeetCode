class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        help(nums, 0, curr);
        ans.push_back({});
        return ans;
    }
    void help(vector<int>& nums, int i, vector<int>& curr){
        if(i >= nums.size()) return;

        curr.push_back(nums[i]);

        
            ans.push_back(curr);
            
        help(nums, i+1, curr);
        curr.pop_back();
        help(nums, i+1, curr);
    }
};