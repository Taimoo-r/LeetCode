class Solution {
public:
    unordered_map<int, int> mp;
    int climbStairs(int n) {
        return helper(n);
    }
    int helper(int n){
        if(mp.count(n)) return mp[n];
        if(n == 0) return 1;

        if(n < 0) return 0;
        mp[n] =  helper(n-1)+helper(n-2);
        return mp[n];
    }
    

};