class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int left, right, ans = 0;
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = i ; j < n  ; j++){
            sum+=nums[j];
            if(sum==k)
            ans++;
        }
    }
    return ans;
    // }
    //     for(int i = 1; i < n ; i++){
    //         if(sum==k){
    //         ans++;
    //         sum=0;
    //         }
    //         else if(sum<k){
    //             sum+=nums[i];
    //         }
    //         else{
    //             sum-=nums[i-1];
    //         }
    //     }
    //     return ans;
    // }
    }
    
};