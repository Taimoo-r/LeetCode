class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string longest = "";
        
        for (int i = 0; i < n; i++) {
            // Handle odd-length palindromes
            string ans = "";
            ans += s[i];
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ans = s[l] + ans + s[r];
                l--, r++;
            }
            longest = ans.size() > longest.size() ? ans : longest;

            // Handle even-length palindromes
            int j = i;
            ans = "";
            while (j < n && s[i] == s[j]) {
                ans += s[j];
                j++;
            }
            l = i - 1;
            r = j; // Continue expanding outward
            while (l >= 0 && r < n && s[l] == s[r]) {
                ans = s[l] + ans + s[r];
                l--, r++;
            }
            longest = ans.size() > longest.size() ? ans : longest;
        }

        return longest;
    }
};
