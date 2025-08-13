class Solution {
public:
    unordered_map<int, int> mp;
    int climbStairs(int n) {
        return helper(n);
    }
    int helper(int n){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(mp.count(n)) return mp[n];
        mp[n] = helper(n-1) + helper(n-2);
        return mp[n];
    }
};