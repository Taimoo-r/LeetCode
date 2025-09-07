class Solution {
public:
    vector<vector<string>> ans;
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        help(0, board);
        return ans.size();
    }
    void help(int row, vector<string> &board){
        if(row == board.size()){
            ans.push_back(board);
            return;
        }

        for(int i = 0 ; i < board.size() ; i++){
            if(isSafe(row, i, board)){
                board[row][i] = 'Q';
                help(row+1, board);
                board[row][i] = '.';
            }
        }
    }

    bool isSafe(int row, int col, vector<string> &board){
        int n = board.size();
        //vertical check
        for(int i = 0 ; i < n ; i++){
            if(board[i][col] == 'Q') return false;
        }

        // upper-left diagonal checks
        for(int i = row, j = col ; i >= 0 && j >=0 ; i--, j--){
            if(board[i][j]=='Q') return false;
        }

        //uper-right diagonal checks
        for(int i = row, j = col; i >= 0 && j < n; i--, j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
};