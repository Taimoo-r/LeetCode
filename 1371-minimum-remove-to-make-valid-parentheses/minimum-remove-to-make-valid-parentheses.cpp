class Solution {
public:
    string minRemoveToMakeValid(string s) {
    //     stack<int> st;
    //     int n = s.size();
        
        
    //     for (int i = 0; i < n; i++) {
    //         if (s[i] == '(') {
    //             st.push(i);
    //         } else if (s[i] == ')') {
    //             if (!st.empty() && s[st.top()] == '(') {
    //                 st.pop();
    //             } else {
    //                 st.push(i);
    //             }
    //         }
    //     }
        
    //     while (!st.empty()) {
    //         s[st.top()] = '#'; 
    //         st.pop();
    //     }
        
    //     string res;
    //     for (int i = 0; i < n; i++) {
    //         if (s[i] != '#') {
    //             res += s[i];
    //         }
    //     }
        
    //     return res;
    // }
    stack<int> st;
        string res;
        int n = s.size();
        
        for(int i = 0 ; i < n; i++){
            if(s[i]=='(')
            st.push(i);
            else if(s[i]==')'){
                if(st.empty() || s[st.top()]==')')
                st.push(i);
                else if(!st.empty() && s[st.top()]=='(')
                st.pop();
            }
        }
        for(int i = n-1; i > -1; i--){
            if(!st.empty() && i==st.top()){
                st.pop();
            }else{
                res+=s[i];
            }
        }
        reverse(res.begin(),res.end());
        return res;
    } 
};
