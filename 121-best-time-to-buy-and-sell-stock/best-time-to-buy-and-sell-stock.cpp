class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxDiff = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            mini = min(mini, prices[i]);
            maxDiff = max(prices[i] - mini, maxDiff);
        }
        return maxDiff;
        
    }
};