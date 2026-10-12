class Solution {
public:
    int merge(vector<int>& nums, int l, int h){
        if(l >= h) return 0;
        int m = l+(h-l)/2;
        int cnt = merge(nums, l, m);
        cnt+=merge(nums, m+1, h);
        int j = m+1;
        for(int i = l ; i <= m ; i++){
            while(j <= h && (nums[i] > (long long)2*nums[j])){
                j++;
            }
            cnt+=j-(m+1);
        }
        int i = l;
        j = m+1;
        vector<int> temp;
        while (i <= m && j <= h) { if (nums[i] <= nums[j]) { temp.push_back(nums[i++]); } else { temp.push_back(nums[j++]); } } while (i <= m) temp.push_back(nums[i++]); while (j <= h) temp.push_back(nums[j++]); for (int k = l; k <= h; k++) { nums[k] = temp[k - l]; } return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size()-1);
    }
};