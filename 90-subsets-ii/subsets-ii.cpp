class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.push_back({});
        help(nums, 0);
        return ans;
    }

    void help(vector<int>& nums, int start){

        for(int i = start ; i < nums.size() ; i++){
            if(i > start && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);
            ans.push_back(curr);
            help(nums, i+1);
            curr.pop_back();
        }
    }
};