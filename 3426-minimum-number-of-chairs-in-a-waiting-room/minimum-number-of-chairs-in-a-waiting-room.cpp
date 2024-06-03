class Solution {
public:
    int minimumChairs(string s) {
        vector<int> arr;
        int res = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='E'){
            res++;
            arr.emplace_back(res);}
            else{
            res--;
            arr.emplace_back(res);}
        }
        auto it = max_element(arr.begin(),arr.end());
        return *it;
    }
};