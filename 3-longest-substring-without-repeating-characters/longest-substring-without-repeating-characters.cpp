class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0 || s.size()==1)
        return s.size();
        int longest = 0;
        int i = 0, j = 0;
        set<char> set;
        while(j < s.size()){
            if(!set.count(s[j])){
                set.insert(s[j]);
                j++;
                longest = max(longest, j-i);
            }
            else{
                set.erase(s[i]);
                i++;
            }
        }
        return longest; 
        
    }
};
