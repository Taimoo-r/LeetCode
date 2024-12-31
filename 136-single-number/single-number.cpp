class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i = 0 ; i < nums.size() ; i+=2){
            if(i < n){
                if(nums[i]!=nums[(i+1)%n])
                    return nums[i];
            }
        }
        return 0;
    }
};