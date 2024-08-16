class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col]=='1'){
                    cnt++;
                    dfs(grid, row, col);
                }
            }
        }
        return cnt;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col]!='0')
        grid[row][col] = '0';
        else return;
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
    }
};