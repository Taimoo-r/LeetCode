class Solution {
public:
    int search(vector<int>& a, int target) {
        int s = 0, e = a.size()-1, ans = INT_MAX;
        int n = a.size();
        while(s <= e){
            int m = s + (e - s)/2;
            if(a[m]==target)
            return m;
            // if right half is sorted
            if(a[m] <= a[e]){
                if(target > a[m] && target <= a[e])
                s = m + 1;
                else 
                e = m-1;
            }
            // if left half is sorted
            else{
                if(target < a[m] && target >= a[s])
                e = m - 1;
                else 
                s = m+1;
            }

        }
        return -1;
        
    }
};