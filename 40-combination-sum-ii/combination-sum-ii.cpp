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
        set<vector<int>> set;
        vector<int> comb;
        helper(nums, target, 0, 0, comb, set);
        return res;
    }

    void helper(vector<int>& nums, int target, int index, int sum, vector<int>& comb, set<vector<int>>& set) {
        if (sum == target) {
            if (set.find(comb) == set.end()) {
                set.insert(comb);
                res.push_back(comb);
            }
            return;
        }

        if (sum > target || index >= nums.size()) {
            return;
        }

        // Inclusion
        comb.push_back(nums[index]);
        helper(nums, target, index + 1, sum + nums[index], comb, set);

        // Exclusion
        comb.pop_back();
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }

        helper(nums, target, index + 1, sum, comb, set);
    }
};
