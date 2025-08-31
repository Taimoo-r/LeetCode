class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    unordered_set<int> st;
    set<vector<int>> s;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));
        help(nums, 0);
        return ans;
    }
    void help(vector<int> &nums, int i){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            
            if(st.count(i)) continue;
            if(i > 0 && nums[i]==nums[i-1] && !st.count(i-1)) continue;
            st.insert(i);
            curr.push_back(nums[i]);
            help(nums, 0);
            curr.pop_back();
            st.erase(i);
        }
    }
};