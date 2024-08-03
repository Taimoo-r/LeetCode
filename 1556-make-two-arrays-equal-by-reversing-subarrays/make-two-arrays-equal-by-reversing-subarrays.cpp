class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target==arr)
        return true;
        set<int> s1(target.begin(),target.end()), s2(arr.begin(),arr.end());
        if(s1.size()!=s2.size())
        return false;
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        return target==arr? true: false;
        
    }
};