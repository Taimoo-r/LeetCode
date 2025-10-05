class Solution {
public:
    int maxi = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int r = 0 ; r < m ; r++){
            for(int c = 0 ; c < n ; c++){
                if(grid[r][c]){
                    int cnt = 0;
                    dfs(grid, r, c, m, n, cnt);
                    maxi = max(cnt, maxi);
                }
            }
        }
        return maxi;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n, int& cnt){
        if(r >= m || c >= n || r < 0 || c < 0 || grid[r][c]==0){
            return;
        }
        cnt++;
        grid[r][c] = 0;

        dfs(grid, r+1, c, m, n, cnt);
        dfs(grid, r-1, c, m, n, cnt);
        dfs(grid, r, c+1, m, n, cnt);
        dfs(grid, r, c-1, m, n, cnt);
    }
};