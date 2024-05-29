class Solution {
public:
    string mergeAlternately(string word1, string word2) {
         int n = word1.length() + word2.length();
        int j = 0, u = 0;
        string res;
        res.reserve(n);  
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                if(j < word1.length()) {
                    res += word1[j++];
                } else if(u < word2.length()) {
                    res += word2[u++];
                }
            } else {
                if(u < word2.length()) {
                    res += word2[u++];
                } else if(j < word1.length()) {
                    res += word1[j++];
                }
            }
        }
        
        return res;
    }
};