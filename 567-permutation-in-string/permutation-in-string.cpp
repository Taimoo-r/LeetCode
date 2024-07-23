class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
        return false;

        vector<int> s1F(26,0), s2F(26,0);

        for(int i = 0; i < s1.size(); i++){
            s1F[s1[i] - 'a']++;
        }
        for(int i = 0 ; i < s1.size() ; i++){
            s2F[s2[i] - 'a']++;
        }
        if(s1F==s2F)
        return true;
        for(int i = s1.size() ; i < s2.size(); i++){
            s2F[s2[i]-'a']++;
            s2F[s2[i - s1.size()] - 'a']--;
            if(s1F==s2F)
            return true;
        }
        return false;
        
    }
};