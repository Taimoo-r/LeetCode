class NumMatrix {
public:
    vector<vector<int>> m;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix;
        for(int i = 0 ; i < matrix.size() ; i++){
            int sum = 0;
            for(int j = 0 ; j < matrix[i].size() ; j++){
                sum+=m[i][j];
                m[i][j] = sum;
            }
        }    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1 ; i <=row2 ; i++){
            sum+= m[i][col2] - (col1 - 1 >= 0 ? m[i][col1-1] : 0);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */