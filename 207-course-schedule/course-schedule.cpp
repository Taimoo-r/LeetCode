class Solution {
public:
    bool isCycle(int root, vector<int> adj[], vector<int> &visited, vector<int> &inStack) {
        visited[root] = true;
        inStack[root] = true;

        for(auto &neighbor : adj[root]) {
            if(!visited[neighbor] && isCycle(neighbor, adj, visited, inStack))
                return true;
            else if(inStack[neighbor])
                return true;
        }

        inStack[root] = false;  // Backtrack, mark this node as no longer in recursion stack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto &req : prerequisites) {
            int course = req[0];
            int prereq = req[1];
            adj[prereq].push_back(course);  // prereq -> course
        }

        vector<int> visited(numCourses, false), inStack(numCourses, false);
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && isCycle(i, adj, visited, inStack))
                return false;  // A cycle is found, can't finish all courses
        }
        return true;  // No cycle found, can finish all courses
    }
};
