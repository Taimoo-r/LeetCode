class Solution {
public:
    string makeGood(string s) {
        string ans;
        stack<char> S;
        for(int i=0;i<s.size();i++){
            if(!S.empty() && abs(s[i]-S.top())==' ')
            S.pop();
            else
            S.push(s[i]);
        }
        while(!S.empty()){
            ans+=S.top();
            S.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
   
};
