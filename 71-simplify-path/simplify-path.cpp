class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        stack<string> st;
        int n = path.size();
        // st.push("/");
        for(int i = 1 ; i < n ; i++){
            if(path[i]=='/') continue;
            string curr = "";
            while(i < n && path[i]!='/'){
                curr+=path[i++];
            }
            if(curr == ".."){
                if(!st.empty()){
                ans = st.top();
                st.pop();
                }
                continue;
            }
            if(curr!="."){
                st.push(ans);
                ans+=("/"+curr);

            }
        }
        return ans.size() == 0 ? "/" : ans;
    }
};