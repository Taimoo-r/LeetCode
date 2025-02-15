class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(auto ch : num){
            while(!st.empty() && st.top()-'0' > ch-'0' && k > 0){
                st.pop();
                k--;
            } 
            if(!st.empty() || ch!='0')
            st.push(ch);

        }

        // case when : 1, 2, 3, 4... increassing, we've to just pop from back large elements;
        while(!st.empty() && k){
            st.pop(); k--;
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top(); st.pop();
        }
        reverse(ans.begin(), ans.end());
        // bool allZero
        return ans.size() > 0 ? ans : "0";
    }
};