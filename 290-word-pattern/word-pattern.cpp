class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string ch="";
        for(int i = 0 ; i < s.size(); i++){
            if(s[i]!=' ')
            ch+=s[i];
             if(s[i]==' ' || i == s.size()-1){
                words.push_back(ch);
                ch = "";
            }
        }
        // for(auto it : words){
        //     cout<<it<<" ";
        // }
        if(words.size()!=pattern.size())
        return 0;
        unordered_map<char,string> mp;
        for(int i  = 0 ; i < pattern.size(); i++){
            mp[pattern[i]] = words[i];
        }
        for(int i = 0 ; i  < pattern.size();i++){
            if(mp[pattern[i]] != words[i])
            return false;
        }
        // mp.clear();
        unordered_map<string,char> p;
        for(int i  = 0 ; i < pattern.size(); i++){
            p[words[i]] = pattern[i];
        }
        for(int i = 0 ; i  < pattern.size();i++){
            if(p[words[i]] != pattern[i])
            return false;
        }
        return true;
        
    }
};