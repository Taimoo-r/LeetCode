class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        for(int i = 0 ; i < n  ; i++){
            int rp = prices[i];
            int j = i + 1;
            while(j < n && prices[j] > rp)
                j++;
            if(j < n){
                ans[i] = rp - prices[j];
            }
            else   
                ans[i] = rp;
        }
        return ans;
    }
};