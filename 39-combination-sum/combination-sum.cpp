class Solution {
public:
    // set<vector<int>> st;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& cand, int t) {
        vector<int> curr;
        help(cand, t, 0, curr, 0);
        return ans;
    }

    void help(vector<int>& cand, int t, int i, vector<int> curr, int sum){
        if(i >= cand.size() || sum > t) return;
        curr.push_back(cand[i]);
        if(sum+cand[i] == t){
            ans.push_back(curr);
        }

        help(cand, t, i, curr,sum+cand[i]);
        curr.pop_back();
        help(cand, t, i+1, curr, sum);

    }
};