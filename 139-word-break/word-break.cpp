class Solution {
public:
    int n;
    unordered_set<string> st;
    int temp[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto it : wordDict){
            st.insert(it);
        }
        memset(temp, -1, sizeof(temp));
        return solve(0, s);
    }
    bool solve(int idx, string &s){
        if(idx >= n) return true;
        if(temp[idx]!=-1) return temp[idx];

        if(st.count(s))
          return temp[idx] = true;

        for(int l = 1 ; l <= n - idx ; l++){
            string tem = s.substr(idx, l);
            if(st.find(tem)!=st.end() && solve(idx + l, s)) 
                return temp[idx] = true;
        }
        return temp[idx] = false;

    }
};