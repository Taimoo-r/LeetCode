class Solution {
public:
    string frequencySort(string s) {
        // map<char, int> mp;
        // for(auto &it : s) mp[it]++;
        // vector<int> idx(62);
        // for(auto &[ch, freq]: mp){
        //     if(ch >= 'a' && ch <= 'z')
        //         idx[ch - 'a'] = freq;
        //     else if(ch >= 'A' && ch <= 'Z')
        //         idx[ch - 'A'+26] = freq;
        //     else
        //         idx[ch - '0'+52] = freq;
        // }
        // for(auto &it : idx) cout<<it<<" ";
        // string ans = "";
        // for(int i = 0 ; i < idx.size() ; i++){
        //     while(idx[i]--){
        //         if(i < 26)
        //             ans += (i + 'a');
        //         else if(i <= 51)
        //             ans+=(i+'A');
        //         else
        //             ans+=(i+'0');
        //     }
        // }
        // return ans;

        map<char, int> mp;
        for(auto &it : s) mp[it]++;

        vector<pair<int, char>> v;
        for(auto &[ch, fq] : mp) v.push_back({fq, ch});

        sort(v.begin(), v.end());

        string ans = "";
        for(int i = v.size() - 1 ; i >=0 ; i--){
            while(v[i].first--){
                ans+=v[i].second;
            }
        }
        return ans;
    }
};