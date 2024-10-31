class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0 ; i < n; i++){
            count++;
            string temp = "";
            temp+=s[i];
            for(int j = i + 1 ; j < n ; j++){
                temp+=s[j];
                string rev = temp;
                reverse(rev.begin(), rev.end());
                if(rev==temp) count++;
            }
        }
        return count;
    }
};