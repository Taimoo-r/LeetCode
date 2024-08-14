class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        set<int> visit;
        for(int i = 0; i < isConnected.size(); i++) {  // Start from index 0
            if(!visit.count(i)) {
                res++;
                dfs(isConnected, visit, i);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& isConnected, set<int>& visit, int source) {  // Pass by reference
        visit.insert(source);
        for(int i = 0; i < isConnected.size(); i++) {
            if(isConnected[source][i] == 1 && !visit.count(i)) {  // Check connection and visit status
                dfs(isConnected, visit, i);
            }
        }
    }
};
