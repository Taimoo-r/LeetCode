class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, en = nums.size() - 1;
        int ans = -1;
        while(st < en){
            int md = st + (en - st) / 2;
            if(nums[md] < nums[en])
                en = md;
            else st = md+1;
        }
        return nums[st];
    }
};