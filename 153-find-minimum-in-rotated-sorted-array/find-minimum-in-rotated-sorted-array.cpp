class Solution {
public:
    int findMin(vector<int>& a) {
        int s = 0 , e = a.size()-1, res = -1;
        int n = a.size()-1;
        if (a[s] < a[e]) {
            return a[s];
        }
        while( s <= e ) {
            int m = (e + s)/2;
            if( m<e && a[m]>a[m+1])
            return a[m+1];
            if(m > s && a[m] < a[m-1])
            return a[m];
            if(a[m] >= a[s])
            s = m + 1;         
            else
            e = m - 1;
        }
        return a[s-1];
    }
};