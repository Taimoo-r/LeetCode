class Solution {
public:
    bool isHappy(int n) {
        set<int> set;
        string s;
        s = to_string(n);
        long res = 0;
        while(res != 1 && res < INT_MAX){
            res = 0;
        for(int i = 0 ; i < s.length() ; i++){
            int p = s[i] - '0';
            res+=pow(p,2);
            
        }
        if(!set.count(res))
        set.insert(res);
        else
        return res==1;
        s = to_string(res);
        cout<<s<<" ";
        }
        return res==1;
        
    }
};