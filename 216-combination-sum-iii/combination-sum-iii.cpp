class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = 0;
        vector<int> curr;
        vector<vector<int>> ans;
        gen(k, n, sum, curr, ans, 1);
        return ans;
    }
    void gen(int k, int t, int& sum, vector<int> &curr, vector<vector<int>> &ans, int i){
        if(sum == t && curr.size() == k){
            ans.push_back(curr);
            return;
        }
        if(sum > t || curr.size() > k || i > 9) return;
        if(sum == t && curr.size() < k) return;
        sum+=i;
        curr.push_back(i);
        gen(k, t, sum, curr, ans, i+1);
        sum-=i;
        curr.pop_back();
        gen(k, t, sum, curr, ans, i+1);

    }
}; 