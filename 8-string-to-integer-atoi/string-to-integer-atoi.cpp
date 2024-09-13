class Solution {
public:
    int myAtoi(string s) {

        // check for leading Space
        int i = 0;
        for(i ; i < s.size() ; i++){
            if(s[i]!=' '){
                break;
            }
        }
        // check for Sign
        int sign = 1;
        if((s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign = -1;
            }
                i++;
        }
        else if(!isdigit(s[i]))
            return 0;
        //now get true string
        long res = 0;
        while( i < s.size() && isdigit(s[i])){
            res = res*10 + (s[i]-'0');
            if(res*sign >= INT_MAX) return INT_MAX;
            if(res*sign <= INT_MIN) return INT_MIN;
            i++;
        }
        return res*sign;
    }
};