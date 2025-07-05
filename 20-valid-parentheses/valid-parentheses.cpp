// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for(auto &it : s){
//             if(it == '(' || it == '{' || it == '['){
//                 st.push(it);
//             }
//             else if(!st.empty() && ((st.top() == '(' && it == ')') || (st.top() == '{' && it == '}') ||
//             (st.top() == '[' && it == ']'))) st.pop();
//             else return false;
//         }
//         return st.empty();
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        while (true) {
            size_t lenBefore = s.size();
            size_t pos;
            while ((pos = s.find("()")) != string::npos) s.erase(pos, 2);
            while ((pos = s.find("[]")) != string::npos) s.erase(pos, 2);
            while ((pos = s.find("{}")) != string::npos) s.erase(pos, 2);

            if (s.size() == lenBefore) break;  
        }

        return s.empty(); 
    }
};