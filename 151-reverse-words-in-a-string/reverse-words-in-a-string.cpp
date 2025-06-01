class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        int start, end;
        for(start = 0 ; start < s.size() ; start++){
            if(s[start] != ' ') break;
        }
        for(end = s.size() - 1 ; end >= 0 ; end--){
            if(s[end] !=' ') break;
        }
        string ans = "";
        for(auto &it : s){
            if(it == ' ' && word.size() > 0){
                words.push_back(word);
                ans = word + " " + ans;
                word = "";
            } 
            else if(it != ' ') word+=it;
        }
        if(word.size() > 0 && word[0]!=' ') {
            words.push_back(word); 
            ans = word + " " + ans;
        }

        return ans.substr(0, ans.size()-1);
    }
};