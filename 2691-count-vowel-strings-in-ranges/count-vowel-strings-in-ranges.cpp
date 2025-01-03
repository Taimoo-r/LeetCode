class Solution {
public:
    bool isvowel(char ch) { return (ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') ||(ch == 'u'); }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size(), 0);
        vector<int> res;
        int n = words.size();
        for(int i = 0 ; i < n ; i++){
            int cnt = 0; 
            if(isvowel(words[i][0]) && isvowel(words[i][words[i].size() - 1]))
                prefix[i] = 1;
            if(i > 0)
                prefix[i]+=prefix[i - 1];
        }
        for(auto query : queries){
            int count = prefix[query[1]];
            if(query[0] > 0)
                count-=prefix[query[0] - 1];
            res.push_back(count);
        }
        return res;
    }
};