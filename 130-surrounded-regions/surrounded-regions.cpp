class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int c = 0 ; c < n ; c++){
            dfs(board, 0, c);
            dfs(board, m - 1, c);
        }

        for(int r = 0 ; r < m ; r++){
            dfs(board, r, 0);
            dfs(board, r, n -1);
        }

        for(int r = 0 ; r < m ; r++){
            for(int c = 0 ; c < n ; c++){
                if(board[r][c]=='T') board[r][c] = 'O';
                else if(board[r][c]=='O') board[r][c] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r >= board.size() || c >= board[0].size() || r < 0 || c < 0 || board[r][c] != 'O' ) return;

        board[r][c]='T';
        dfs(board, r+1, c);
        dfs(board, r, c+1);
        dfs(board, r-1, c);
        dfs(board, r, c-1);
    }
};
