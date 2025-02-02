class Solution {
public:
    // string DtoB(int x){
    //     string ans = "";
    //     while(x > 0){
    //         ans+=x%2+'0';
    //         x/=2;
    //     }
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    // }
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};