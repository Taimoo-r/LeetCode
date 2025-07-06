class Solution {
public:
    int eval(int a, int b, string op){
        if (op == "+") return a+b;
        if (op == "-") return b-a;
        if (op == "*") return a*b;
        return b/a; 
        }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &it : tokens){
            if(it == "+" || it == "-" || it == "*" || it == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(eval(a, b, it));
            } else{
                st.push(stoi(it));
            }
        }
        return st.top();
        
    }
};