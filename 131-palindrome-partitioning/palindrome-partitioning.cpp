class Solution {
public:
    bool isPal(string s){
        int l = 0, r = s.size() - 1;
        while(l < r){
            if(s[l++]!=s[r--]) return 0;
        }
        cout<<s<<" "<<endl;
        return 1;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        string curr = "";
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
            if( isPal(s.substr(idx, i-idx+1))){
                v.push_back(s.substr(idx, i-idx+1));
                gen(s, ans, v, i+1);
                v.pop_back();
            }
        }
    }
};