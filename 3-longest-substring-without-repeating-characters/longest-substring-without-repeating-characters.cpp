class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;
        int left, right;
        left = right = 0;
        int len = 0;
        while(right < s.size()){
            char curr = s[right];

            while(st.count(curr)){
                st.erase(s[left]);
                left++;
            }
            st.insert(curr);
            len = max(right - left + 1, len);
            right++;
            
        }
        return len;
    }
};