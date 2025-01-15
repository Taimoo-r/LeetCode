class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxCnt = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')'){
                maxCnt = max(cnt, maxCnt);
                cnt--;
            }
        }
        return maxCnt;
    }
};