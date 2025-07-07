class Solution {
public:
    vector<string> v;
    bool valid(string s) {
        stack<char> st;
        for(auto &it : s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }
            else if(!st.empty() && ((st.top() == '(' && it == ')') || (st.top() == '{' && it == '}') ||
            (st.top() == '[' && it == ']'))) st.pop();
            else return false;
        }
        return st.empty();
    }
    vector<string> generateParenthesis(int n) {
        generate(n, "");
        return v;
    }

    void generate(int n, string ans){
        if(ans.size() == n*2){
            if(valid(ans)) v.push_back(ans);
            return;
        }
        generate(n, ans+'(');
        generate(n, ans+')');
    }
};