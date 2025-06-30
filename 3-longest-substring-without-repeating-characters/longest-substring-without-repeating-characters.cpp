class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;
        int maxLen = 0;
        int n = s.size();
        for(int l = 0, r = 0 ; r < n ; r++){
            while(l < r && st.count(s[r])){
                st.erase(s[l++]);
            }
            st.insert(s[r]);
            maxLen = max(r - l + 1, maxLen);
        }
        return maxLen;
        
    }
};