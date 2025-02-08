class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        map<int, int> mp;
        for(int i = 0 ; i < n ; i++) mp[nums2[i]] = i;
        stack<int> st;
        vector<int> v(n, -1);
        for(int i = n - 1 ; i >= 0 ; i--){
            if(!st.empty()){
                while(!st.empty() && st.top() <= nums2[i])
                    st.pop();
                if(!st.empty()){
                    v[i] = st.top();
                    st.push(nums2[i]);
                }
            }
            if(st.empty()){
                st.push(nums2[i]);
                v[i] = -1;
            }
        }
        vector<int> res;
        for(auto &it : nums1){
            int idx =  mp[it];
            res.push_back(v[idx]);
        }
        return res;
    }
};