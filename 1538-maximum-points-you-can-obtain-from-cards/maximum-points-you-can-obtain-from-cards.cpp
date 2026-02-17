class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int sum = 0;
        int n = v.size();
        for(int i = n - 1 ; i >= n - (k-1) ; i--) sum+=v[i];
        int maxi = 0;
        for(int i = 0, j = n-(k-1) ; i < k ; i++, j++){
            sum+=v[i];
            maxi = max(sum, maxi);
            if(j < n)
            sum-=v[j];
        }
        sum = 0;
        for(int i = 0 ; i < k-1 ; i++) sum+=v[i];
        for(int i = n-1, j = k-2 ; i >= n-k ; i--, j--){
            sum+=v[i];
            maxi = max(sum, maxi);
            if(j >= 0)
            sum-=v[j];
        }
        return maxi;
    }
};