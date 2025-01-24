class Solution {
public:
    bool isPal(string s, int st, int en){
        while(st < en){
            if(s[st++]!=s[en--]) return 0;
        }
        return 1;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        gen(s, ans, v, 0);
        return ans;
    }
    void gen(string &s, vector<vector<string>> &ans, vector<string> &v,int idx){
        if(idx >= s.size()){
            ans.push_back(v);
            return;
        }
        for(int i = idx ; i < s.size() ; i++){
            if( isPal(s, idx, i)){
                v.push_back(s.substr(idx, i-idx+1));
                gen(s, ans, v, i+1);
                v.pop_back();
            }
        }
    }
};