class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int, int> mp1, mp2;
        for(auto &it : s1) mp2[it]++;
        int n = s2.size();
        int k = s1.size();
        for(int l = 0, r = 0 ; r < n ; r++){
            while(r - l >= k){
                mp1[s2[l]]--;
                if(mp1[s2[l]]==0) mp1.erase(s2[l]);
                l++;
            }
            mp1[s2[r]]++;
            if(mp1 == mp2) return true;
        }
        return false;
    }
};