class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> arr[n+1];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i!=j && isConnected[i][j]==1){
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }
        for(int i = 0; i < n ; i++){
            cout<<"Node "<<i+1<<" : ";
            for(auto it : arr[i]){
                cout<<it+1<<" ";
            }
            cout<<endl;
        }
        int res = 0;
        set<int> visit, visitDFS;
        for(int i = 0 ; i < n ; i++){
            if(!visit.count(i)){
                res++;
                dfs(arr, visit, i);
            }
        }
        return res;
        
    }
    void dfs(vector<int> adj[], set<int>& visit, int source){
        visit.insert(source);
        for(auto it : adj[source]){
            if(!visit.count(it) ){
                dfs(adj, visit, it);
            }
        }


    }
};