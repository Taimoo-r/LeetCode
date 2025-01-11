class Solution {
public:
    int merge(vector<int> &nums, int lt, int md, int rt){
        int cnt = 0;
        int right = md+1;

        for(int i = lt ; i <= md ; i++){
            while(right <= rt && nums[i] > 2LL*nums[right])
                right++;
            cnt+= (right - md - 1);
        }
        int l = lt, r = md+1;
        int k = 0;
        vector<int> temp(rt - lt + 1);
        while(l <= md && r <= rt){
            if(nums[l] <= nums[r])
                temp[k++] = nums[l++];
            else
                temp[k++] = nums[r++];
        }
        while(l <= md) temp[k++] = nums[l++];
        while(r <= rt) temp[k++] = nums[r++];

        for(int i = lt, k=0 ; i <= rt ; i++,k++)
            nums[i] = temp[k];
        return cnt;
    }

    int half(vector<int> &nums, int lt, int rt){
        if(lt>=rt) return 0;
        int cnt = 0;
        
        int md = lt + (rt - lt)/2;
        cnt+=half(nums, lt, md);
        cnt+=half(nums, md+1, rt);
        cnt+=merge(nums, lt, md, rt);
        
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return half(nums, 0, nums.size() - 1);
    }
};