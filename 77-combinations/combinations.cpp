class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        help(n, k, 1, curr);
        return ans;
    }

    void help(int n, int k, int start, vector<int>& curr) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            help(n, k, i + 1, curr);
            curr.pop_back(); // backtrack
        }
    }
};
