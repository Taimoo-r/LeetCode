class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int, int> mp;
        int maxi = 0;

        int l = 0;
        int n = f.size();
        for(int r = 0 ; r < n ; r++){
            mp[f[r]]++;

            while(mp.size() > 2){
                mp[f[l]]--;
                if(mp[f[l]]==0) mp.erase(f[l]);
                l++;
            }
            
            maxi = max(maxi, r-l+1);
        }
        return maxi;
    }
};