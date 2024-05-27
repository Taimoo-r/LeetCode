class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        return false;
        int a[26] = {};
                for(int i=0;i<s.length();i++){
                    int temp = (int)s[i];
                    a[temp-97]++;
                    temp = (int)t[i];
                    a[temp-97]--;
                }
        for(int i=0;i<26;i++){
            if(a[i]!=0)
            return false;
        }
        return true;
    }
};