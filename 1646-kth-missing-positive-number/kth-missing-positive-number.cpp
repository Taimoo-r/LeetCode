class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v;
        set<int> s(arr.begin(), arr.end());
        // int maxi = *max_element(arr.begin(), arr.end());
        for(int i = 1 ; i < 5000 ; i++){
            if(!s.count(i)) v.push_back(i);
        }
        cout<<arr.size();
        cout<<v.size();
        return v[k-1];
    }
};