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

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> comb;
        helper(nums, target, 0, comb);
        return res;
    }

    void helper(vector<int>& nums, int target, int index, vector<int>& comb) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }

        for (int i = index; i < nums.size() && nums[i] <= target; i++) {
            if (i > index && nums[i] == nums[i - 1]) continue; // Skip duplicates

            comb.push_back(nums[i]);
            helper(nums, target - nums[i], i + 1, comb);  // i + 1 to move to the next index
            comb.pop_back();  // Backtrack
        }
    }
};
