class Solution {
public:
    // bool search(int i, vector<int>& nums){
    //     int st = 0, end = nums.size()-1;
    //     while(st <= end){
    //         int md = st + (end - st)/2;
    //         if(md!=i && nums[md]==nums[i]){
    //             return true;
    //         }
    //         else if(nums[md] > nums[i]) end = md - 1;
    //         else st = md + 1;
    //     }
    //     return false;

    // }
    int findDuplicate(vector<int>& nums) {
        for(int i  = 0 ; i < nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0)
                return abs(nums[i]);
            else
                nums[abs(nums[i])-1]*=-1;
        }
        return 0;
    }
};