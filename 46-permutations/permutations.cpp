class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        set<int> st;
        
            help(nums, curr, 0, st);
    
        return ans;
    }

    void help(vector<int> &nums, vector<int> &curr, int i, set<int>& st){
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(int j = 0 ; j < nums.size() ; j++){
            if(st.count(j)) continue;
            st.insert(j);
            cout<<nums[j]<<" ";
            curr.push_back(nums[j]);
            help(nums, curr, j+1, st);
            st.erase(j);
            curr.pop_back();
        }
    }
};