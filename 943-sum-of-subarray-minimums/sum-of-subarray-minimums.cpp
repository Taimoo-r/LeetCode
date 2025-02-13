class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        int MOD = (int)(1e9 + 7);

        vector<int> left(n), right(n);
        stack<int> st;
        // we will prepare the left vector in a way that how many times a ith element remains smaller in every subarray from [i, unkonwn]
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            left[i] = st.empty() ? i+1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();
        // right :  same as left

        for(int i = n - 1; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            right[i] = st.empty() ? n - i : st.top() - i; 

            st.push(i);
        }


        long long minSum = 0;
        for (int i = 0; i < n; i++) {
            minSum = (minSum + (long long) arr[i] * left[i] * right[i]) % MOD;
        }
        

        return minSum;
    }
};