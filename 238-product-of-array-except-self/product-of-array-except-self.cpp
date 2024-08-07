class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int pre = 1;
        for(int i = 1 ; i < n ; i++){
            res[i] = res[i-1]*nums[i-1];
        }
        for(int i = n - 1; i >-1 ; i--){
            res[i]*=pre;
            pre *= nums[i];
        }
        return res;
    }
};
