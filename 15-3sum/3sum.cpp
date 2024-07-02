class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, k;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0 ; i < n; i++){
            if(i > 0 && nums[i]==nums[i-1])
            continue;
            j = i + 1;
            k = n - 1;
            while(j < k){
                if(nums[i]+nums[j]+nums[k]==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j]==nums[j+1]) j++;
                    while(j < k && nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0)
                j++;
                else
                k--;
            }
        }
        return res; 
    }
};