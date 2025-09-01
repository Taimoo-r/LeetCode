class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    bool isPal(string s){
        for(int i = 0, j = s.size() - 1 ; i < s.size() ; i++, j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        help(s, 0);
        // if(isPal(s))
        // ans.push_back({s});
        return ans;
    }
    void help(string s, int i){
        if(i >= s.size()){
            ans.push_back(curr);
        }

        for(int j = i ; j < s.size() ; j++){
            if(!isPal(s.substr(i, j-i+1))) continue;
            curr.push_back(s.substr(i, j-i+1));
            help(s, j+1);
            curr.pop_back();
        }
    }

};