class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Store allowed characters in a set
        unordered_set<char> allow(allowed.begin(), allowed.end());
        
        int count = 0;
        for(const auto& word : words){
            bool ok = true;
            for(const auto& ch : word){
                if(!allow.count(ch)){
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
