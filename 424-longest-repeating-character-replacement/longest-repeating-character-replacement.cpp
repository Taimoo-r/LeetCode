class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> mp;
        int maxF = 0;
        int ans = 0;
        int n = s.size();
        for(int l = 0, r = 0; r < n ; r++){
           mp[s[r]]++;
           maxF = max(maxF, mp[s[r]]);
           while((r - l+1) - maxF > k){
            mp[s[l]]--;
            l++;
           }
           
           ans = max(ans, r - l+1);
        }
        return ans;
        
    }
};