class Solution {
public:
    void entireZero(vector<vector<int>>& matrix, int row, int col){
        //make row zero
        for(int i = 0 ; i < matrix[row].size() ; i++)
            matrix[row][i] = 0;

        //lets now booyahhhhh
        int totalRows = matrix.size();
        for(int i = 0 ; i < totalRows ; i++)
            matrix[i][col] = 0;
        return;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> initialZero; 
        for(int row = 0 ; row < matrix.size() ; row++){
            for(int col = 0 ; col < matrix[row].size() ; col++){
                if(matrix[row][col]==0) initialZero.push_back({row, col});
            }
        }
        
        for(int i = 0 ; i < initialZero.size() ; i++){
            int row = initialZero[i].first;
            int col = initialZero[i].second;
            entireZero(matrix, row, col);
        }
        
    }
};