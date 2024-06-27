class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size()<3)
        return 0;
        int c = 0;
        string r;
        for(int i =  0 ; i <= s.size()-3 ; i++ ){
            r = s.substr(i,3);
            unordered_set<char> se(r.begin(),r.end());
            if(se.size()==3)
            c++;
        }
        return c;
    }
};