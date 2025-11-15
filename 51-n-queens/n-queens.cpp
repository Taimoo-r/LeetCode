class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        string fill = "";
        for(int i = 0 ; i < n ; i++) fill+='.';
        vector<string> v(n, fill);
        backtrack(v, n, 0);
        return res;
    }

    bool isSafe(vector<string> v, int n, int r, int c){
        for(int i = 0 ; i < n ; i++){
            if(v[i][c] == 'Q') return false;
        }

        for(int i = 0 ; i < n ; i++){
            if(v[r][i] == 'Q') return false; 
        }

        for(int row = r-1, col = c-1 ; row >= 0 && col >= 0 ; row--, col--){
            if(v[row][col] == 'Q') return false;
        }
        for(int row = r-1, col = c+1 ; row >= 0 && col < n ; row--, col++){
            if(v[row][col] == 'Q') return false;
        }
        return true;
    }

    void backtrack(vector<string> v, int n, int r){
        if(r >= n){
            res.push_back(v);
            return;
        }

        for(int col = 0 ; col < n ; col++){
            if(isSafe(v, n, r, col)){
                v[r][col] = 'Q';
                backtrack(v, n, r+1);
                v[r][col] = '.';
            }
        }
    }
};