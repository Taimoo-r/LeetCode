class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        set<int> st;
        int cnt = 0;
        for(int i = 0 ; i < isConnected.size() ; i++){
            if(!st.count(i)){
                dfs(isConnected, st, i);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(vector<vector<int>>& isConnected, set<int> &st, int i){
        if(st.count(i)) return;
        st.insert(i);
        for(int it = 0 ; it < isConnected[i].size() ; it++){
            if(!st.count(it) && isConnected[i][it]!=0){
                dfs(isConnected, st, it);
            }
        }

    }
};