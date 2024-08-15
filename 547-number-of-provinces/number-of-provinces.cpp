class Solution {
public:
    int findCircleNum(vector<vector<int>>& con) {
        int res=0;
        set<int> visit;
        cout<<con.size();
        for(int i = 0; i < con.size(); i++){
            if(!visit.count(i)){
                res++;
                dfs(con, visit, i);
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &con, set<int> &visit, int source){
        visit.insert(source);
        for(int i = 0 ; i < con.size(); i++){
            if(con[source][i]==1 && !visit.count(i)){
                dfs(con, visit, i);
            }
        }
    }
};