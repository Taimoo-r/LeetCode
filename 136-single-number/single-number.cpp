class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i =0 ; i < nums.size(); i++){
            if(i-1 >=0 && i+1 < n && (nums[i]^nums[i+1])!=0 && (nums[i]^nums[i-1])!=0) return nums[i]; 
            if(i-1 < 0 && (nums[i]^nums[i+1])!=0) return nums[i];
            if(i+1 >= n && (nums[i]^nums[i-1])!=0) return nums[i];
        }
        return 0;
    }
};