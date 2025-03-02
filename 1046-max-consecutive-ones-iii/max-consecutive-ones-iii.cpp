class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxOne = 0;
        int l, r;
        int cnt = k;
        l = r = 0;
        while(r < n){
            int curr = nums[r];

            if(nums[r]==0) cnt--;

            while(cnt < 0){
                if(nums[l++]==0)
                    cnt++;
            }

            maxOne = max(maxOne, r - l + 1);
            r++;

        }
        return maxOne;
    }
};