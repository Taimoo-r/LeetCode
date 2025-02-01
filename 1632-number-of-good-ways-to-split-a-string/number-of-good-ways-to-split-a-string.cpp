class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        map<char, int> sl, sr;
        sl[s[0]]++;
        for(int i = 1 ; i < n ; i++) sr[s[i]]++;
        int cnt = 0;
        int l = 0, r = 1;
        while(l < r && r < n){

            cnt+=sl.size() == sr.size();
            sl[s[r]]++;
            sr[s[r]]--;
            if(sr[s[r]]==0) sr.erase(s[r]);
            l++;
            if(r + 1 < n) r++;
        }
        return cnt;
        
    }
};