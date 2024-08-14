class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int res=0;
       const int n = isConnected.size();
       set<int> visited;
       for(int i = 0 ; i < n ; i++){
            if(!visited.count(i)){
                res++;
                dfs(isConnected, visited, i);
            }
       }
       return res;
    }
    void dfs(vector<vector<int>> &isConnected, set<int>& visited, int source){
        visited.insert(source);
        for(int i = 0 ; i < isConnected.size() ; i++){
            if(isConnected[source][i]==1 && !visited.count(i)){
                dfs(isConnected, visited, i);
            }
        }
    }
};
