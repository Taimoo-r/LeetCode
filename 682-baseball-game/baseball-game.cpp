class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto &it : operations){
            if(it == "C" && !st.empty()) st.pop();
            else if(it == "D" && !st.empty()) st.push(st.top()*2);
            else if (it == "+" && !st.empty()) {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a);
                st.push(b);
                st.push(a+b);
            }
            else {st.push(stoi(it));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};