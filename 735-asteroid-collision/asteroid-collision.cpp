class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ass) {
        int n = ass.size();
        stack<int> st;

        for(auto &it : ass){
            bool thisAssDestroyed = false;
            while(!st.empty() && st.top() > 0 && it < 0 && !thisAssDestroyed){
                int a = st.top();
                if(abs(a) < abs(it)){
                    st.pop();
                }
                else if(abs(a)==abs(it)){
                    st.pop();
                    thisAssDestroyed = true;
                }
                else{
                    thisAssDestroyed = true;
                }
            }
            if(!thisAssDestroyed)
            st.push(it);
        }
        vector<int> v(st.size());
        for(int i = st.size() - 1 ; i >= 0 ; i--){
            v[i] = st.top();
            st.pop();
        }
        return v;
    }
};