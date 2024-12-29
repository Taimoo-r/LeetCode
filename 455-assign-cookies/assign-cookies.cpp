class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gSize = g.size();
        int cSize = s.size();
        // vector<pair<int,bool>> chk;
        // vector<pair<int,bool>> gg;
        // for(int i = 0 ; i < gSize ; i++) gg.push_back({g[i], false});
        // for(int i = 0 ; i < cSize ; i++) chk.push_back({s[i],false});
        // int cnt = 0;
        // for(int i = 0 ; i < gSize; i++){
        //     for(int j = 0 ; j < cSize ; j++){
        //         if(gg[i].first>=chk[j].first && chk[j].second == false && gg[i].second == false){
        //             gg[i].second = true;
        //             chk[j].second = true;
        //             cnt++;
        //         }
        //     }
        // }
        
        // return cnt;
        int cnt = 0;
        int l = 0, r = 0;
        while( l < gSize && r < cSize){
            if(g[l] <= s[r]){
                cnt++;
                l++;
                r++;
            }
            else if(g[l] > s[r]) r++;
        }
        return cnt;

    }
};