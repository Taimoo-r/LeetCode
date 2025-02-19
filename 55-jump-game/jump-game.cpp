class Solution {
public:
    vector<int> dp; // Memoization array

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1); // Initialize memoization array
        return check(nums, 0);
    }

    bool check(vector<int>& nums, int index) {
        if (index >= nums.size() - 1) return true;  // Base case: reached last index
        if (nums[index] == 0) return false;         // Can't jump further
        if (dp[index] != -1) return dp[index];      // Use memoized result

        for (int i = nums[index]; i > 0; i--) { // Try all jumps from current index
            if (check(nums, index + i)) {
                return dp[index] = true; // Cache result and return true
            }
        }
        return dp[index] = false; // Cache result and return false
    }
};
