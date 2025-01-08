class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
//         int ll, rr;
//         ll = 0, rr = nums.size() - 1;
//         sort(nums.begin(), nums.end());
//         set<vector<int>> st;
//         while(ll < rr){
//             int l = ll + 1, r = rr - 1;
//             while(l < r){
//                 long long sum = nums[ll]+nums[rr]+nums[l]+nums[r];
//                 if(sum < t){
//                     if(ll - l < 0)
//                         l++;
//                     else
//                         ll++;
//                 }
//                 else if(sum > t){
//                     if(rr - r < 2)
//                         r--;
//                     else
//                         rr--;
//                 }
//                 else if(sum == t){
//                     // push logic
//                     if(!st.count({nums[ll],nums[rr],nums[l],nums[r]})){
//                         ans.push_back({nums[ll],nums[rr],nums[l],nums[r]});
//                         st.insert({nums[ll],nums[rr],nums[l],nums[r]});
//                     }
//                     l++, r--;
//                 }
//             } 
//                 ll++, rr--;
//         }
//         return ans;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int ll = 0 ; ll < nums.size() ; ll++){
            if(ll > 0 && nums[ll]==nums[ll - 1]) continue;

            for(int rr = ll + 1 ; rr < nums.size(); rr++){
                if(rr > ll + 1 && nums[rr]==nums[rr - 1]) continue;
                int l = rr + 1, r = nums.size() - 1;
                while(l < r){
                    long long sum = (long long)nums[ll]+(long long)nums[rr]+(long long)nums[l]+(long long)nums[r];
                    if(sum == t){
                        ans.push_back({nums[ll],nums[rr],nums[l],nums[r]});
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(r > l && nums[r] == nums[r-1]) r--;
                        l++, r--;
                    }
                    else if(sum > t)
                        r--;
                    else
                        l++;
                }
            }
        }  
            return ans;
    }
};                             