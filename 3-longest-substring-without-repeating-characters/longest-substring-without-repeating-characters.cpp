class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            set<char> st;
            for(int j = i ; j < n ; j++){
                if(st.count(s[j])){
                    maxLen = max(maxLen, j - i);
                    break;
                }
                st.insert(s[j]);
            }
            maxLen = max(maxLen, (int)st.size());
        }
        return maxLen;
    }
};