class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        vector<int> v;
        v = arr;
        sort(v.begin(),v.end());
        int peak = v.back();
        map<int,int> mp;
        for(int i = 0 ; i < arr.size(); i ++){
            mp[arr[i]] = i;
        }
        return mp[peak];
    }
};