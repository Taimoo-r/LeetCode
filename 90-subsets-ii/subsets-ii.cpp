class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        ans.push_back({});
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        gen(nums, curr, ans, 0, st);
        return ans;
    }
    void gen(vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans, int i, set<vector<int>> &st){
        if(i>=nums.size()) return;
        curr.push_back(nums[i]);
        if(!st.count(curr)){
            ans.push_back(curr);
            st.insert(curr);
        }
        gen(nums, curr, ans, i+1, st);
        curr.pop_back();
        gen(nums, curr, ans, i+1, st);
    }
};