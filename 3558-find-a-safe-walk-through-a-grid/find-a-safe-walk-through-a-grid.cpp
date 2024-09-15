class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, -1));
        if (grid[0][0] == 1) {
            health--;
        }
        if (health <= 0) return false; 
        q.push({{0, 0}, health});
        vis[0][0] = health;
        while (!q.empty()) {
            auto [pos, currHealth] = q.front();
            auto [x, y] = pos;
            q.pop();
            if (x == m - 1 && y == n - 1 && currHealth > 0) {
                return true;
            }
            for (auto [dx, dy] : dir) {
                int newX = x + dx;
                int newY = y + dy;
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    int newHealth = currHealth - (grid[newX][newY] == 1 ? 1 : 0);
                    if (newHealth > 0 && newHealth > vis[newX][newY]) {
                        q.push({{newX, newY}, newHealth});
                        vis[newX][newY] = newHealth;
                    }
                }
            }
        }
        return false;
    }
};