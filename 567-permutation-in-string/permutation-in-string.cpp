class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Freq(26, 0), s2Freq(26, 0);

        // Initialize frequency array for s1
        for (char c : s1) {
            s1Freq[c - 'a']++;
        }

        // Initialize frequency array for the first window of s2
        for (int i = 0; i < s1.size(); i++) {
            s2Freq[s2[i] - 'a']++;
        }

        // Check if the first window is a permutation of s1
        if (s1Freq == s2Freq) return true;

        // Slide the window over s2
        for (int i = s1.size(); i < s2.size(); i++) {
            s2Freq[s2[i] - 'a']++;
            s2Freq[s2[i - s1.size()] - 'a']--;
            if (s1Freq == s2Freq) return true;
        }

        return false;
    }
};
