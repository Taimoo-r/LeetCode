class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> S1,S2;
        for(int i=0;i<s.size();i++){
            if(s[i]!='#')
            S1.push(s[i]);
            else if(s[i]=='#' && S1.empty()==false)
            S1.pop();
           }
        for(int i=0;i<t.size();i++){
            if(t[i]!='#')
            S2.push(t[i]);
            else if(t[i]=='#' && S2.empty()==false)
            S2.pop();
        }
        while(!S1.empty() && !S2.empty()){
            if(S1.top()!=S2.top())
            return false;
            S1.pop();
            S2.pop();
        }
        if(S1.empty()&&S2.empty())
        return true;
        else
        return false;
    }
};