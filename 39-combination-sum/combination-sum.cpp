class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currCombo; // Initialize an empty vector to store the current combination
        helper(nums, target, 0, 0, currCombo);
        return res;
    }

    void helper(vector<int>& nums, int target, int currSum, int currIndex, vector<int>& currCombo) {
        if (currSum == target) {
            res.push_back(currCombo);
            return;  // Return early after finding a valid combination
        }

        if (currSum > target || currIndex >= nums.size()) {
            return;  // If sum exceeds target or we've checked all numbers, return
        }

        // Include the current number in the combination and recurse
        currCombo.push_back(nums[currIndex]);
        helper(nums, target, currSum + nums[currIndex], currIndex, currCombo);

        // Exclude the current number from the combination (backtrack) and recurse
        currCombo.pop_back();
        helper(nums, target, currSum, currIndex + 1, currCombo);
    }
};
