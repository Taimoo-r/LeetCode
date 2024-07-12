class Solution {
public:
    // void getSort(vector<string>& strs){
    //     for(int i = 0 ; i < strs.size(); i++){
    //         sort(strs[i].begin(),strs[i].end());
    //     }
    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //    set<string> s;
    //    vector<vector<string>> res;

    //    vector<string> u = strs;
    //    getSort(u);
    //    for(int i = 0 ; i < strs.size(); i++){
    //        if(s.find(strs[i])!=s.end())
    //        continue;
    //        s.insert(strs[i]);
    //        vector<string> sub;
    //        sub.push_back(strs[i]);
    //        string r = u[i];
    //        for(int j = i + 1; j < strs.size(); j++){  ** \U0001f642 1528 ms **
    //         string c = u[j];
    //         if(r==c){
    //             sub.push_back(strs[j]);
    //             s.insert(strs[j]);
    //         }
    //        }
    //        res.push_back(sub);
    //    }
    //    return res;
    vector<vector<string>> res;
        map<string, vector<string>> mp;
        
        for (auto& it : strs) {
            string s = it;
            sort(s.begin(), s.end());
            mp[s].push_back(it); 
        }
        
        for (auto& it : mp) {
            res.push_back(it.second);
        }
        
        return res;
    }
};