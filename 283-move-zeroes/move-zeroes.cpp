class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int z = 0;
        for(auto &it : nums) if(it==0)z++;
        int j = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]!=0) swap(nums[i], nums[j++]);
        }
        // for(j ; j < n ; j++){
        //     nums[i]==0;
        // }
    }
};