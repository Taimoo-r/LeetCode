// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> curr;
//         set<vector<int>> st;
//         gen(nums, ans, curr, 0, st);
//         return ans;
//     }
//     void gen(vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr, int i, set<vector<int>> &st){
//         if(i >= nums.size()) return;
//         curr.push_back(nums[i]);
//         if(!st.count(curr)){
//         ans.push_back(curr);
//         st.insert(curr);
//         }
//         gen(nums, ans, curr, i+1, st);
//         curr.pop_back();
//         if(!st.count(curr)){
//         ans.push_back(curr);
//         st.insert(curr);
//         }
//         gen(nums, ans, curr, i+1, st);

//     }
// };

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        gen(nums, ans, curr, 0);
        ans.push_back({}); // Include the empty subset explicitly
        return ans;
    }
    
    void gen(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int i) {
        if (i == nums.size()) return;
        
        // Include nums[i]
        curr.push_back(nums[i]);
        ans.push_back(curr);
        gen(nums, ans, curr, i + 1);
        
        // Exclude nums[i]
        curr.pop_back();
        gen(nums, ans, curr, i + 1);
    }
};
