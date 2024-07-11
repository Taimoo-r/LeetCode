class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.size();
        
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }
        
        while (!st.empty()) {
            s[st.top()] = '#'; 
            st.pop();
        }
        
        string res;
        for (int i = 0; i < n; i++) {
            if (s[i] != '#') {
                res += s[i];
            }
        }
        
        return res;
    }
};
