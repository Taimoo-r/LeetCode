class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        fill(image, sr, sc, color, vis, image[sr][sc]);
        return image;
    }
    void fill(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& vis, int currCol){
        if(vis[sr][sc] || image[sr][sc]!=currCol) return;
        vis[sr][sc] = 1;

        image[sr][sc] = color;
        
        if(sr+1 < image.size() && image[sr+1][sc] == currCol) fill(image, sr+1, sc, color, vis, currCol);
        if(sr-1 >= 0 && image[sr-1][sc] == currCol) fill(image, sr-1, sc, color, vis, currCol); 
        if(sc+1 < image[0].size() && image[sr][sc+1] == currCol) fill(image, sr, sc+1, color, vis, currCol);
        if(sc-1 >= 0 && image[sr][sc-1] == currCol) fill(image, sr, sc-1, color, vis, currCol);
    }
};