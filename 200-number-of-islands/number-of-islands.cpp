class Solution {
public:
    int cnt = 0;
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int r = 0 ; r < m ; r++){
            for(int c = 0 ; c < n ; c++){
                if(grid[r][c]=='1'){
                    dfs(grid, r, c, m, n);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<char>>& grid, int r, int c, int m, int n){
        if(r >= m || c >= n || r < 0 || c < 0 || grid[r][c]=='0'){
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r+1, c, m, n);
        dfs(grid, r-1, c, m, n);
        dfs(grid, r, c+1, m, n);
        dfs(grid, r, c-1, m, n);
    }
};