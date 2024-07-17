class Solution {
public:
    int findMin(vector<int>& a) {
        int s = 0, e = a.size()-1;
        // if(a[s] < a[e])
        // return a[s];
        set<int> set(a.begin(),a.end());
        for(auto it : set){
            return it;
        }
        
        // while(s <= e){
        //     int m = (s + e) / 2;
        //      67
        // }
        return 0;
    }
};