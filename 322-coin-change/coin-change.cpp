class Solution {
public:
    unordered_map<int, int> mp;
    int coinChange(vector<int>& coins, int amount) {
        int ans = rec(coins, amount);
        return ans == 1e9 ? -1 : ans;
    }

    int rec(vector<int> coins, int a){
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