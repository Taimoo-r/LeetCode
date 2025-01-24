class Solution {
public:
    bool isSafe(vector<vector<string>> &board, int row, int col){
        // horizontal
        int n = board.size();
        // vertical
        for(int i = 0 ; i < n ; i++)
            if(board[i][col]=="Q") return false;
        // primary diagnoal (back)
        for(int c = col, r = row ; c >= 0 && r >= 0; c--, r--)
            if(board[r][c]=="Q") return false;
        // primary diagnoal (front)
        for(int c = col, r = row ; c < n && r < n; c++, r++)
                if(board[r][c]=="Q") return false;
        // secondary diagnoal (back)
        for(int c = col, r = row ; c < n && r >= 0; c++, r--)
                if(board[r][c]=="Q") return false;
        // secondary diagnol (front)
        for(int c = col, r = row ; c >= 0 && r < n; c--, r++)
                if(board[r][c]=="Q") return false;
        return true;    
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<string>> board(n, vector<string>(n, "."));
        gen(board, ans, 0, 0, n);
        return ans;
    }
    void gen(vector<vector<string>> &board, vector<vector<string>> &ans, int cnt, int row, int n){
        if(cnt == n){
             vector<string> temp;
            for (auto &r : board) {
                string s = "";
                for (auto &c : r) {
                    s += c;
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }
        if(row >= n) return;

        for(int c = 0 ; c < n ; c++){
            if(isSafe(board, row, c)){
                board[row][c] = "Q";
                gen(board, ans, cnt+1, row+1, n);
                board[row][c] = ".";
            }
        }
    }
};