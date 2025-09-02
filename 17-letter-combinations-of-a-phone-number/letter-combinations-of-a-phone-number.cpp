class Solution {
public:
    vector<string> ans;
    string get(char c){
        if(c == '2') return "abc";
        else if(c == '3') return "def";
        else if(c == '4') return "ghi";
        else if(c == '5') return "jkl";
        else if(c == '6') return "mno";
        else if(c == '7') return "pqrs";
        else if(c == '8') return "tuv";
        else return "wxyz";
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() <= 0) return {};
        help(digits, 0, "");
        return ans;
    }
    void help(string digits, int i, string curr){
        if(curr.size() == digits.size()){
            ans.push_back(curr);
            return;
        }

        string str = get(digits[i]);

        for(auto &it : str){
            help(digits, i+1, curr+it);
        } 
    }
};