class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length()<3)
        return 0;
        int count = 0;
        
        unordered_set<char> ss;
        for(int i = 0 ; i <= s.size()-3;i++){
            // unordered_set<char> ss;
            for(int j = i; j < 3+i ; j++){
                
                ss.insert(s[j]);
            }
            if(ss.size()==3)
            count++;
            ss.clear();
        }
        return count;
    }
};