class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int> adj[n];
        makeList(edges, adj);
        set<int> visit;
        return dfs(adj, src, dest, visit);
    }

    bool dfs(vector<int> adj[], int src, int dest, set<int>& visit){
        if(src==dest)
        return true;
        if(visit.count(src))
        return false;
        visit.insert(src);
        for(auto neighbor : adj[src]){
            if(dfs(adj, neighbor, dest, visit))
            return true;
        }
        return false;
    }


    void makeList( vector<vector<int>>& edges, vector<int> adj[] ){
        int n = edges.size();
        for(int i = 0 ; i < edges.size() ; i++){
            int f = edges[i][0];
            int s = edges[i][1];
            adj[f].push_back(s);
            adj[s].push_back(f);
        }
    }
};