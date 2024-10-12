class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // Edge case: empty input
        if (strs.size() == 1) return strs[0];  // If there's only one string, return it
        
        string res = "";  // Result to store the longest common prefix
        for (int i = 0; i < strs[0].size(); i++) {
            char check = strs[0][i];  // Character from the first string to compare
            bool found = true;  // Flag to check if all strings match
            
            for (int j = 1; j < strs.size(); j++) {
                // Check if we are within the bounds of the current string and if the character matches
                if (i >= strs[j].size() || strs[j][i] != check) {
                    found = false;
                    break;
                }
            }
            
            if (found) {
                res += check;  // Append the character if all strings match
            } else {
                break;  // Stop once we find a mismatch
            }
        }
        
        return res;
    }
};
