class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int maxLen = 0;
        // int n = s.size();
        // for(int i = 0 ; i < n ; i++){
        //     set<char> st;
        //     for(int j = i ; j < n ; j++){
        //         if(st.count(s[j]))h{
        //             maxLen = max(maxLen, j - i);
        //             break;
        //         }
        //         st.insert(s[j]);
        //     }
        //     maxLen = max(maxLen, (int)st.size());
        // }
        // return maxLen;
        int n = s.size();
        int l, r;
        set<char> st;
        int maxLen = 0;
        l = r = 0;
        while(r < n){
            char curr = s[r];

            while(st.count(curr))
                st.erase(s[l++]);
            
            maxLen = max(maxLen, r - l + 1);
            st.insert(curr);
            r++;
        }
        return maxLen;
    }
};