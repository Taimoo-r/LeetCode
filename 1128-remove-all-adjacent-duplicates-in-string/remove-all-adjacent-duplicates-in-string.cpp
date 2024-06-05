class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> S;
        string ans;
        for(int i=0;i<s.size();i++){
            if(S.empty() || s[i]!=S.top())
            S.push(s[i]);
            else if(!S.empty() && s[i]==S.top())
            S.pop();
        }
        while(!S.empty()){
            ans+=S.top();
            S.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};