class Solution {
public:
    unordered_map<int, int> mp;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        for(int i = 1 ; i <= amount ; i++){
            for(auto &c : coins){
                if(i-c >= 0){
                    dp[i] = min(dp[i], dp[i-c]+1);
                }
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }

    int rec(vector<int>& coins, int a){
        if(a == 0) return 0;
        if(mp.count(a)) return mp[a];
        int mini = 1e9;
        for(auto &x : coins){
            int res = 1e9;
            if(a-x >= 0){
                res = rec(coins, a-x);
            }
            mini = min(res+1, mini);
        }
        mp[a] = mini;
        return mini;
    }
};