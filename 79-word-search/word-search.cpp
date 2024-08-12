class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowSize = board.size();
        int colSize = board[0].size();
        for(int row = 0 ; row < rowSize; row++){
            for(int col = 0 ; col < colSize ; col++){
                if(word[0]==board[row][col]){
                    if(helper(board, word, row, col, 0))
                    return true;
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, string word, int row, int col, int index){
        if(index == word.size())
        return true;
        if(row >= board.size() || row < 0 || col >= board[0].size() || col < 0 || board[row][col]!=word[index])
        return false;
        if(board[row][col]=='#')
        return false;
        board[row][col]= '#';
        if( helper(board, word, row - 1, col, index + 1)
            || helper(board, word, row + 1, col, index + 1)
            || helper(board, word, row, col - 1, index + 1)
            || helper(board, word, row, col + 1, index + 1))
            return true;
        board[row][col] = word[index];
        return false;
    }
};