class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        unordered_set<char> allow(allowed.begin(), allowed.end());
        int count = 0;
        for(int i = 0 ; i < words.size(); i++){
            bool ok = true;
            for(int j = 0 ; j < words[i].size(); j++){
                if(!allow.count(words[i][j])){
                    ok = false;
                    break;
                }
            }
            if(ok)
                count++;
        }
        return count;
        
    }
};