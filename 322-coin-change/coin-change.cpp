class Solution {
public:
    int mini = INT_MAX;
    unordered_map<int, int> memo;

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int ans = rec(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }

    int rec(vector<int>& c, int a){
        if(a == 0) return 0;
        if(memo.count(a)) return memo[a];

        int res = INT_MAX;

        for(auto &x : c){
            if(a - x < 0) break;

            int sub = rec(c, a - x);
            if(sub != INT_MAX){
                res = min(res, sub + 1);
            }
        }

        return memo[a] = res;
    }
};