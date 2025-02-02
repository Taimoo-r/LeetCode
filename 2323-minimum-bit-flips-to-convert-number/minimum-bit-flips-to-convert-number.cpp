class Solution {
public:
    string DtoB(int x){
        string ans = "";
        while(x > 0){
            ans+=x%2+'0';
            x/=2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int minBitFlips(int start, int goal) {
        int mi = start^goal;
        string b = DtoB(mi);
        int c = 0;
        for(auto &it : b){
            if(it=='1') c++;
        }
        return c;
    }
};