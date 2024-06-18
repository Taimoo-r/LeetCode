class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        bool get = 1;
        for(int i = s.size()-1 ; i>-1 && get == 1; i--){
            if(s[i]!=' '){
                get = 0;
                while(i>-1 && s[i]!=' '){
                    count++;
                    i--;
                }
            }
        }
        return count;
    }
};