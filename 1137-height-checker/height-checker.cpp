class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> exp;
        exp = heights;
        int res=0;
        sort(heights.begin(),heights.end());
        for(int i=0;i<exp.size();i++){
            if(heights[i]!=exp[i])
            res++;
        }
        return res;
    }
};