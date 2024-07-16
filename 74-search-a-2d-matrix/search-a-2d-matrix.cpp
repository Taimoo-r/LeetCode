class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int r = 0;
        for(int i = 0 ; i < row ; i++){
            if(matrix[i][0] <= target && matrix[i][matrix[i].size()-1] >= target){
                r = i;
                break;
            }
        }
        cout<<r;
        int s = 0, e = matrix[r].size()-1;
        cout<<" "<<e;
        while(s<=e){
            int m = (s+e)/2;
            if(matrix[r][m]==target)
            return true;
            else if(matrix[r][m]>target){
                e = m - 1;
            }
            else if(matrix[r][m]<target){
                s = m +1;
            }
        }
        return false;

        
    }
};