class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length()<3)
        return 0;
        int count = 0;
        int i = 0;
        for(int j = 2; j < s.length(); j++){
            if(s[i]!=s[i+1] && s[i]!=s[j] && s[j]!=s[i+1])
            count++;
            i += 1;
        }
        return count;
    }
};