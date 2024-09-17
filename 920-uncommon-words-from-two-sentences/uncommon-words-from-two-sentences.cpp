class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        string word = "";
        for(int i = 0 ; i < s1.size(); i++){
            if(s1[i]!=' ')
                word+=s1[i];
            else{
                mp[word]++;
                word = "";
            }
        }
        mp[word]++;
        word="";
        for(int i = 0 ; i < s2.size(); i++){
            if(s2[i]!=' ')
                word+=s2[i];
            else{
                mp[word]++;
                word = "";
            }
        }
        mp[word]++;
        vector<string> s;
        for(auto it : mp){
            if(it.second < 2){
                s.push_back(it.first);
            }
        }
        return s;
    }
};