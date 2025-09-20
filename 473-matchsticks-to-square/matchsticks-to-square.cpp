class Solution {
public:
    set<int> st;
    bool makesquare(vector<int>& mt) {
        int sum = 0;
        for(auto &it : mt) sum+=it;
        if(sum%4!=0) return false;
        int req = sum/4;
        sort(begin(mt), end(mt));
        return help(mt, 0, req, 0, 0);
    }

    bool help(vector<int>& mt, int i, int req, int sum, int side){
        if(side == 3) return true;
        if(sum == req){
            return help(mt, 0, req, 0, side+1);
        }
        if(i >= mt.size() || sum > req) return false;


        for(int j = i ; j < mt.size() ; j++){
            if(j > i && mt[j] == mt[j-1] && !st.count(j-1)) continue;
            if(!st.count(j) && mt[i]+sum <= req){
                st.insert(j);
                if(help(mt, j, req, sum+mt[j], side)) return true;
                st.erase(j);
            }
        }
        return false;
    }
};