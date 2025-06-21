class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sum = 0;
        int low = prices[0];
        for(int i = 0 ; i < n ; i++){
            if(low <= prices[i]){
                sum+=prices[i]-low;
                low = prices[i];
            }
            else{
                low = prices[i];
            }
        }
        return sum;
        
    }
};