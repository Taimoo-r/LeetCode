class Solution {
public:
    string getString(char ch) {
        if(ch == '2') return "abc";
        else if(ch == '3') return "def";
        else if(ch == '4') return "ghi";
        else if(ch == '5') return "jkl";
        else if(ch == '6') return "mno";
        else if(ch == '7') return "pqrs";
        else if(ch == '8') return "tuv";
        else if(ch == '9') return "wxyz";
        return "";
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};  // Handle empty input
        
        vector<string> result;
        result.push_back("");  // Initialize with empty string for combinations

        for(char digit : digits) {
            string letters = getString(digit);
            vector<string> temp;
            
            for(string &comb : result) {
                for(char letter : letters) {
                    temp.push_back(comb + letter);
                }
            }
            
            result = temp; 
        }

        return result;
    }
};
