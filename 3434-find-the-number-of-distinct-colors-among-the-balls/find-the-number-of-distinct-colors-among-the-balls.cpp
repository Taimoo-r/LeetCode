class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp; // Maps ball -> color
        unordered_map<int, int> st; // Maps color -> count of balls with that color
        vector<int> ans;
        int colorCount = 0; // Number of unique colors

        for(auto& q : queries) {
            int ball = q[0], newColor = q[1];

            // If the ball already has a color
            if (mp.count(ball)) {
                int oldColor = mp[ball];

                // Decrease count of the old color
                if (--st[oldColor] == 0) {
                    colorCount--; // If no balls left with oldColor, decrease color count
                }
            }

            // Assign the new color to the ball
            mp[ball] = newColor;
            
            // Increase count of the new color
            if (++st[newColor] == 1) {
                colorCount++; // If it's a new color, increase color count
            }

            ans.push_back(colorCount);
        }

        return ans;
    }
};
