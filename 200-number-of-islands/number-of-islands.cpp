class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        set<pair<int,int>> s;
        int res = 0;
        for(int row = 0 ; row < grid.size(); row++){
            for(int col = 0 ; col < grid[row].size(); col++){
                if(!s.count({row,col}) && grid[row][col]=='1'){
                    res++;
                    dfs(grid, s, row, col);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, set<pair<int,int>>& s, int row, int col){
        s.insert({row,col});
        vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
        for(auto dir : directions){
            int drow = row + dir.first;
            int dcol = col + dir.second;
            if(drow >= 0 && drow < grid.size() && dcol >= 0 && dcol < grid[drow].size() && grid[drow][dcol]=='1' && !s.count({drow, dcol})){
                s.insert({drow,dcol});
                dfs(grid, s, drow, dcol);
            }
        }
    }
};