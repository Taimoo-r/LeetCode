class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            map<char, int> freq; // Frequency map for characters in the current substring
            for (int j = i; j < n; j++) {
                freq[s[j]]++; // Update frequency for current character
                
                int maxi = 0, mini = INT_MAX;
                for (auto &[ch, count] : freq) {
                    maxi = max(maxi, count);
                    mini = min(mini, count);
                }
                
                if (freq.size() > 1) // Ensure there are at least 2 distinct characters
                    ans += (maxi - mini);
            }
        }
        return ans;
    }
};
