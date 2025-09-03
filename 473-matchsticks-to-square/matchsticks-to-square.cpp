class Solution {
public:
    bool makesquare(vector<int>& mt) {
        int sum = 0;
        for(auto &it : mt) sum+=it;
        if(sum%4!=0) return false;
        sort(mt.rbegin(), mt.rend());
        int len = sum/4;
        vector<int> sides(4, 0);
        return help(mt, sides, len, 0);
    }

    bool help(vector<int>& mt, vector<int> &sides, int len, int i){
        if(i >= mt.size()){
            return sides[0]==len && sides[1]==len && sides[2]==len && sides[3]==len;
        }

        for(int j = 0 ; j < 4 ; j++){
            if(sides[j]+mt[i] <= len){
                sides[j]+=mt[i];
                if(help(mt, sides, len, i+1)) return true;
                sides[j]-=mt[i];
            }
        }
        return false;
    }
};