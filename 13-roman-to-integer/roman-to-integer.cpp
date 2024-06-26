class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<string,int> mp;
        mp["I"] = 1,mp["V"] = 5, mp["X"] = 10,mp["L"] = 50 , mp["C"] = 100 ,mp["D"] = 500, mp["M"] = 1000;
        for(int i = 0;i< s.size() ; i++){
            if(i<s.size()-1 && mp[string(1,s[i])]<mp[string(1,s[i+1])]){
                res += mp[string(1, s[i + 1])] - mp[string(1, s[i])];
                i++;
            }
            else
            res+=mp[string(1,s[i])];
        }
        return res;
    }
};