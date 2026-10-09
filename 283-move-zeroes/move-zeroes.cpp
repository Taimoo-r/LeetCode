class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = n;
        int i = 0;
        int j = 0;
        while(i < n){
            if(nums[i]==0){
                j = i;
                while(j < n - 1 && nums[j]==0) j++;
                reverse(nums.begin()+i, nums.begin()+j+1);
            }
            i++;
        }
    }
};