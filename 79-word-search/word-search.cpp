class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0 ; r < board.size() ; r++){
            for(int c = 0 ; c < board[r].size() ; c++){
                if(board[r][c] == word[0]){
                    if(help(board, word, r, c, 0))
                        return true;
                }
            }
        }
        return false;
    }

    bool help(vector<vector<char>>& board, string& word, int r, int c, int i){
        if(i >= word.size()) return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[r].size()) return false;
        if(board[r][c] == '#') return false;
        if(board[r][c] != word[i]) return false;

        int original = board[r][c];
        board[r][c] = '#';

        bool left = help(board, word, r, c - 1, i+1);
        bool right = help(board, word, r, c + 1, i+1);
        bool up = help(board, word, r - 1, c, i+1);
        bool down = help(board, word, r + 1, c, i+1);

        board[r][c] = original;
        return (left || right || up || down);
    }
};