class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res=0;
        unordered_map<char,char> hm;
        for(auto j : jewels){
            hm[j] = j;
        }
        for(auto s : stones){
            if(hm.find(s)!=hm.end())
            res++;
        }
        return res;
    }
};