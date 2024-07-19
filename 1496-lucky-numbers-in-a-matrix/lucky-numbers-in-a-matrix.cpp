class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& m) {
        vector<int> r;
        vector<int> c(m[0].size(),INT_MIN);
        vector<int> res;
        int n = m.size();
        int cmx = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int rmi = INT_MAX;
            for(int j = 0 ; j < m[0].size(); j++){
                rmi = min(rmi,m[i][j]);
                c[j] = max(c[j],m[i][j]);
            }
            r.push_back(rmi);
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m[i].size();j++){
                if(m[i][j]==r[i] && m[i][j]==c[j])
                res.push_back(c[j]);
            }

        }
        return res;
    }
};