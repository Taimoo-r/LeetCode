class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int curr : asteroids) {
            bool destroyed = false;

            while (!st.empty() && curr < 0 && st.top() > 0) {
                if (abs(curr) > abs(st.top())) {
                    st.pop(); // current survives, top is destroyed
                } else if (abs(curr) == abs(st.top())) {
                    st.pop(); // both destroyed
                    destroyed = true;
                    break;
                } else {
                    // current asteroid is destroyed
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(curr);
            }
        }

        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};
