class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans ;
        for(int row = 0 ; row < board.size(); row++){
            for(int col = 0 ; col < board[row].size(); col++){
                if(word[0] == board[row][col]){
                if(helper(board, word , col, row, 0))
                return true;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, string &word, int col, int row, int index){
        if(index >= word.size()){
            return true;
        }
        if(row >= board.size() || board[row].size() <= col || row <0 || col < 0 || board[row][col]==' ' || board[row][col]!=word[index]){
            return false;
        }
        board[row][col] = ' ';

        if(helper(board, word, col, row+1, index + 1) || helper(board, word, col-1, row, index + 1) || helper(board, word, col+1, row, index + 1) || helper(board, word, col, row-1, index + 1) )
        return true;
        board[row][col] = word[index];
        return false;
    }
};
