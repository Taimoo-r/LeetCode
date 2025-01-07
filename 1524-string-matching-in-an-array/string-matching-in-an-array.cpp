class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> st;
        int n = words.size();
        vector<string> ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i!=j && words[i].find(words[j])!=string::npos){
                    if(!st.count(words[j]))
                    ans.push_back(words[j]);
                    st.insert(words[j]);
                }
            }
        }
        return ans;
    }
};