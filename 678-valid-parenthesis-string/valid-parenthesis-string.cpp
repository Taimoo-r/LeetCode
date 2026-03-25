class Solution {
public:
    bool checkValidString(string s) {
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        return rec(s, 0, 0, dp);
    }
    bool rec(string &s, int i, int open, int dp[][101]){
        if(open < 0) return false;
        if(i >= s.size()){
            return open == 0;
        }
        if(dp[i][open]!=-1) return dp[i][open];
        bool valid = false;
        if(s[i]=='(') valid|=rec(s, i+1, open+1, dp);
        else if(s[i]==')') valid|=rec(s, i+1, open-1, dp);
        else valid|=rec(s, i+1, open+1, dp) || rec(s, i+1, open-1, dp) || rec(s, i+1, open, dp);
        return dp[i][open] = valid;
    }
};