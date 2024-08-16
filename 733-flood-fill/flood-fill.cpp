class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(color!=initialColor)
        dfs(image, sr, sc, color, initialColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int inC){
        if(sr < 0 || sr >= image.size() || sc < 0 && sc >= image[0].size() || image[sr][sc]!=inC)
        return;
        image[sr][sc] = color;
        dfs(image, sr, sc + 1, color , inC);
        dfs(image, sr, sc - 1, color , inC);
        dfs(image, sr + 1, sc, color , inC);
        dfs(image, sr - 1, sc, color , inC);

    }
};