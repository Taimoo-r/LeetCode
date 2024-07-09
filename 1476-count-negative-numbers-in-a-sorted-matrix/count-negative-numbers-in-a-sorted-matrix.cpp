class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int u = grid.size();
        cout<<u;
        int n = 0;
    for(auto g : grid){
        for(int i = g.size()-1; i > -1 ; i--){
            if(g[i]<0)
            n++;
        }
    }
    return n;
        
    }
};