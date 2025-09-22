class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i = 0 ; i < order.size() ; i++) mp[order[i]] = i;

        for(int k = 0 ; k < words.size() - 1 ; k++){
            string c = words[k];
            string n = words[k+1];
            int i, j;
            for(i = 0, j = 0 ; i < c.size() && j < n.size() ; i++, j++){
                if(mp[c[i]] < mp[n[j]]) break;

                if(mp[c[i]] > mp[n[j]]) return false; 
            }
            if(j == n.size() && i < c.size()) return false;
        }
        return true;

    }
};