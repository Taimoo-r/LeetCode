class Solution {
public:
    int findMin(vector<int>& a) {
        int s = 0, e = a.size()-1;
        int n = a.size()-1;
        int ans = INT_MAX;
        // if(a[s] < a[e])
        // return a[s];
        while(s <= e){
            int m = (s+e)/2;
             ans = min(ans, a[m]);
            if (a[m] == a[s]) {
                s++;
            } else if (a[m] == a[e]) {
                e--;
            } else if (a[m] >= a[s]) {
                ans = min(ans, a[s]);
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return ans;
    }
};