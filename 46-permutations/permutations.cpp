class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> visit(nums.size(), 0);
        for(int i = 0 ; i < nums.size() ; i++){
            if(!visit[i]){
                helper(nums, i, res, visit, temp);
            }
        }
        return res;
    }
    void helper(vector<int>& nums, int i, vector<vector<int>> &res, vector<int> &visit, vector<int> &temp){
        visit[i] = 1;
        temp.push_back(nums[i]);
        if(temp.size()==nums.size()){
            res.push_back(temp);
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(!visit[i])
                helper(nums, i, res, visit, temp);
        }
        visit[i] = 0;
        temp.pop_back();
    }
};