class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        int u=0;
        for(int i=0;i<s.length();i++){
            if(((int)s[i]>=65 && (int)s[i]<=90) || ((int)s[i]>=97 && (int)s[i]<=122) || ((int)s[i]>=48 && (int)s[i]<=57)){
                ans+=tolower(s[i]);
                cout<<ans[u++];
            }
        }
        s=ans;
        int j=ans.length()-1;
        for(int i=0;i<ans.length()/2;i++){
            swap(ans[i],ans[j--]);
        }
        if(s==ans)
        return true;
        else
        return false;
    }
};