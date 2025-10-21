class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, adj, vis, pathVis))
                    return true;  
            }
            else if (pathVis[neighbor]) {
                return true;  
            }
        }
        
        pathVis[node] = 0; 
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        
        vector<vector<int>> adj(numCourses);

        // build directed graph correctly: b → a
        for (auto &e : prereq) {
            int a = e[0];
            int b = e[1];
            adj[b].push_back(a);
        }

        vector<int> vis(numCourses, 0), pathVis(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return false;  
            }
        }
        return true;  
    }
};
