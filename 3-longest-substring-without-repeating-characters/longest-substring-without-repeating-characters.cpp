class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int left,right,ans;
        // left = right = ans = 0;
        // int n = s.size();
        // set<string> S;
        // while(left < n && right < n){
        //     if(S.count(s[right]){
        //         while(S[left]==S[right]){
        //             left++;
        //         }
        //         S.erase(left-1);
        //     }
        //     else{
        //         S.insert(S[right]);
        //     }
        //     int Size = S.size();
        //     ans = max(size,ans);
        // }
        // return ans;
        unordered_set<char> se;
        vector<unordered_set<char>> v;
        int count = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n && se.find(s[j])==se.end();j++){
                se.insert(s[j]);
            }
            v.push_back(se);
            se.clear(); 
        }
        int mx = 0;
      for(int i = 0; i < v.size(); i++) {
        int t = v[i].size();
        mx = max(mx,t);
    }
        return mx;
    }
};