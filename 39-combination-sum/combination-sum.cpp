#pragma GCC optimize("O3")
#pragma GCC target("arch=znver3")
namespace _xd {
    static const auto _ = [] {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        return 0;
    }();
}
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currCom;
        helper(nums,target,0,0, currCom);
        return res;
        
    }
    void helper(vector<int> &nums, int target, int index, int sum, vector<int>& comb){
        if(sum==target){
            res.push_back(comb);
            return;
        }
        if(sum > target || index >= nums.size()){
            return;
        }
        comb.push_back(nums[index]);
        helper(nums, target, index,sum + nums[index], comb);
        comb.pop_back();
        helper(nums,target, index + 1, sum , comb);
    }
};