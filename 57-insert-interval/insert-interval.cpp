class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ne) {
        int n = in.size(); 
        vector<vector<int>> res;
        int i = 0;
        bool started = 0;
        for(; i < n ; i++){
            if(in[i][0] > ne[1]) {
                
                break;
            };
            if(in[i][1] >= ne[0]){
                started = 1;
                ne[0] = min(in[i][0], ne[0]);
                ne[1] = max(in[i][1], ne[1]);
            }
            else if(!started){
                res.push_back(in[i]);
            } else if(started) break;
        }
        res.push_back(ne);
        for(int j = i ; j < n ; j++){
            res.push_back(in[j]);
        }
        return res;
        
    }
};