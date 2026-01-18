class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        int maxF = 1, maxi = 1;
        for(int l = 0, r = 0 ; r < n; r++){
            mp[s[r]]++;
            maxF = max(maxF, mp[s[r]]);

            while(r-l+1 - maxF > k){
                mp[s[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
        }
        return maxi;
    }
};