class Solution {
public:
    bool anotherRange(string &s, int i, int n){
        while(i < n){
            if(s[i++]!=s[n--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int cnt = 0;
        int n = s.size()-1;
        int i = 0;
        while(i < n){
            if(s[i]!=s[n]){
                return anotherRange(s, i+1, n) || anotherRange(s, i, n-1);
            }
            i++, n--;
        }
        return true;
    }
};