class Solution {
public:
    bool isSubsequence(string s, string t) {
        string ans="";
        int u=0;
        for(int i=0;i<t.size();i++){
            if(t[i]==s[u]){
                ans+=t[i];
                u++;
            }
        }
        if(ans==s)
        return true;
        else
        return false;
    }
};