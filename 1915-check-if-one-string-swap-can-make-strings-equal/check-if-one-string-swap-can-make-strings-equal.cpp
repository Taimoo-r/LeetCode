class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        int l = 0, r = s1.size() - 1;
        bool left = false, right = false;
        while(l < r && (!left || !right)){
            if(s1[l]!=s2[l])
                left = true;
            if(s1[r]!=s2[r])
                right = true;
            if(!left) l++;
            if(!right) r--;
        }
        cout<<l<<" "<<r;
        if(l == r) return false;
        
           
            swap(s1[l], s1[r]);
        
        return s1 == s2 ? true : false;
    }
};