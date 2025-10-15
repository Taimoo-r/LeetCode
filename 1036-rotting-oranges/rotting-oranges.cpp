class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int minutes = 0;
        int fresh = 0;

        // Step 1: Count fresh oranges and queue all rotten ones
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) fresh++;
                else if (grid[r][c] == 2) q.push({r, c});
            }
        }

        // If there are no fresh oranges, return 0 immediately
        if (fresh == 0) return 0;

        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // Step 2: BFS to rot fresh oranges
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false; // track if at least one orange rots this minute
            
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front(); q.pop();
                
                for (auto &d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if (rotted) minutes++; // only count minute if something changed
        }

        return (fresh == 0) ? minutes : -1;
    }
};
