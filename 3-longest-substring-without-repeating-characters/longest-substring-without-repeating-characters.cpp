class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left,right,ans;
        left = right = ans = 0;
        int n = s.size();
        set<char> S;
        while(left < n && right < n){
            if(S.find(s[right])==S.end()){
                S.insert(s[right]);
                right++;
                ans = max(ans,right-left);
                }
            else{
                S.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};
//         unordered_set<char> se;
//         vector<unordered_set<char>> v;
//         int count = 0;
//         int n = s.size();
//         for(int i = 0 ; i < n ; i++){
//             for(int j = i ; j < n && se.find(s[j])==se.end();j++){
//                 se.insert(s[j]);
//             }
//             v.push_back(se);
//             se.clear(); 
//         }
//         int mx = 0;
//       for(int i = 0; i < v.size(); i++) {
//         int t = v[i].size();
//         mx = max(mx,t);
//     }
//         return mx;
//     }
// };