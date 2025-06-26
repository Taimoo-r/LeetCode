// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         k%=nums.size();
//         vector<int> ans;
//         int n = nums.size();
//         for(int i = n - k ; i < n; i++){
//             ans.push_back(nums[i]);
//         }

//         ans.insert(ans.end(), nums.begin(), nums.end() - k);
//         nums = ans;
//     }
// };

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};