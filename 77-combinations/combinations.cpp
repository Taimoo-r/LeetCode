class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        for(int i = 1 ; i <= n ; i++){
            help(n, k, curr, i);
        }
        return ans;
    }
    void help(int n, int k, vector<int> curr, int i){
        if(i > n || curr.size() > k) return;

        curr.push_back(i);

        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }

        for(int j = i ; j <= n ; j++){
            help(n, k, curr, j+1);
            // curr.pop_back();
        }
    }
};