class Solution {
public:
    int nCr(int n, int r){
        int res = 1;
        for(int i = 0 ; i < r ; i++){
            res*=(n-i);
            res/=(i+1);
        }
        return res;
        
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int n = 0 ; n < numRows ; n++){
            vector<int> v;
            for(int r = 0 ; r <= n ; r++){
                long long ans = nCr(n, r);
                v.push_back(ans);
            }
            res.push_back(v);
        }
        return res;
        
    }
};