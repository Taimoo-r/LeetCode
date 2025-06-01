class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string ans = "";
        for(auto &it : s){
            if(it == ' ' && word.size() > 0){
                ans = word + " " + ans;
                word = "";
            } 
            else if(it != ' ') word+=it;
        }
        if(word.size() > 0 && word[0]!=' ') {
            ans = word + " " + ans;
        }

        return ans.substr(0, ans.size()-1);
    }
};