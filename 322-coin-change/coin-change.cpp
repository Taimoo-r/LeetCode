class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);  // Initialize the dp array
        dp[0] = 0;  // Base case: no coins are needed for amount 0

        // Iterate over each amount from 1 to target amount
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still INT_MAX, it means we cannot make up the amount
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
