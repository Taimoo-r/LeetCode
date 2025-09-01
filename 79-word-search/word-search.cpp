class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0 ; r < board.size() ; r++){
            for(int c = 0 ; c < board[r].size() ; c++){
                if(board[r][c] == word[0]){
                    if(help(board, word, r, c))
                        return true;
                }
            }
        }
        return false;
    }

    bool help(vector<vector<char>>& board, string word, int r, int c){
        if(word.size() == 0) return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[r].size()) return false;
        if(board[r][c] == '#') return false;
        if(board[r][c] != word[0]) return false;

        int original = board[r][c];
        board[r][c] = '#';

        bool left = help(board, word.substr(1), r, c - 1);
        bool right = help(board, word.substr(1), r, c + 1);
        bool up = help(board, word.substr(1), r - 1, c);
        bool down = help(board, word.substr(1), r + 1, c);

        board[r][c] = original;
        return (left || right || up || down);
    }
};