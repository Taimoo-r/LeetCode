class Solution {
public:
    int climbStairs(int n) {
        vector<int> rev(n+1, -1);
        return helper(n, rev);
    }
    int helper(int n , vector<int> &rev){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(rev[n] != -1) return rev[n];
        rev[n] = helper(n - 1, rev) + helper(n-2, rev);
        return rev[n];
    }
};