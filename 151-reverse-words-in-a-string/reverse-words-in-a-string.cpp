class Solution {
public:
    string reverse(string s){
        return string(s);
    }
    string reverseWords(string s) {
        vector<string> v;
        string par = "";
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i]!=' ') par+=s[i];
            else if(s[i]==' '){
                if(par.size() > 0)
                    v.push_back(par);
                par = "";
            }
        }
        if(par.size() > 0) v.push_back(par);
        string ans = "";
        for(int i = v.size() - 1 ; i >= 0 ; i--){
            ans+=v[i];
            if(i > 0 && i < v.size())
                ans+=" ";
        }
        return ans;

    }
};