class Solution {
public:
    bool isValid(string &s){
        stack<char> st;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='(')
                st.push(s[i]);
            else{
                if(st.empty()) return 0;
                else if(st.top()!='(') return 0;
                else st.pop();
            }
            
        }
        if(st.empty()) return 1;
        else return 0;
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> v;
        string ans;
        gen(s, ans, v, n);
        return v;
    }
    void gen(string &s, string &ans, vector<string> &v, int n){
        if(ans.size() == n*2){
            if(isValid(ans))
                v.push_back(ans); 
            return;
        }
        ans.push_back('(');
        gen(s, ans, v, n);
        ans.pop_back();
        ans.push_back(')');
        gen(s, ans, v, n);
        ans.pop_back();
    }
};