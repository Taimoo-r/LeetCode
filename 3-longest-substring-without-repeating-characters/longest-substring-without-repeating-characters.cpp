class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> mp;

        int maxi = 0;
        int n = s.size();
        int l = 0;
        for(int r = 0 ; r < n ; r++){
            mp[s[r]]++;

            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }

            maxi = max(maxi, r - l+1);
        }        
        return maxi;
    }
};