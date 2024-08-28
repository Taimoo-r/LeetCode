class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> pacific(row,vector<int>(col));
        vector<vector<int>> atlantic(row,vector<int>(col));

        // Dfs Call 
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(i == 0 || j == 0)
                    dfs(heights, pacific, i, j, INT_MIN);
                if(i == row - 1 || j == col - 1)
                    dfs(heights, atlantic, i, j, INT_MIN);
            }
        }


        // Making Solution(res) matrix
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(pacific[i][j] && atlantic[i][j])
                res.push_back({i,j});
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int row, int col, int prev){
        if(row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size()) return;
        if(prev > heights[row][col] || ocean[row][col]) return;

        ocean[row][col] = 1;

        dfs(heights, ocean, row + 1, col, heights[row][col]);
        dfs(heights, ocean, row - 1, col, heights[row][col]);
        dfs(heights, ocean, row, col + 1, heights[row][col]);
        dfs(heights, ocean, row, col - 1, heights[row][col]);
    }
};