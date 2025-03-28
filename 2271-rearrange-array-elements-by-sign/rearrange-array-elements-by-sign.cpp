class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1;
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0 ; i < n ; i++){
            if(nums[i] >= 0){
                res[pos] = nums[i];
                pos+=2;
            }
            else{
                res[neg] = nums[i];
                neg+=2;
            }
        }
        return res;
        
    }
};