class Solution {
public:
    int peri = 0;
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int row = 0 ; row < grid.size() ; row++){
            for(int col = 0 ; col < grid[row].size() ; col++){
                if(grid[row][col] == 1){
                    dfs(grid, row, col);
                    break;
                }
            }
        }
        return peri;
    }

    void dfs(vector<vector<int>>& grid, int r, int c){
        if(r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0 || grid[r][c] == 0) {
            peri++;
            return;
        }
        if(grid[r][c] == -1) return;

        grid[r][c] = -1;

        dfs(grid, r, c+1); // right
        dfs(grid, r, c-1); // left
        dfs(grid, r+1, c); // down
        dfs(grid, r-1, c);
    }
};