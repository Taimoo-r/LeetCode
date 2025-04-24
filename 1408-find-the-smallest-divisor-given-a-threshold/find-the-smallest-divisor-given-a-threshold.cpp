class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto calc = [&](int mid) {
            int result = 0;
            for (int it : nums) {
                result += (it + mid - 1) / mid; // Optimized ceil
            }
            return result;
        };

        int left = 1, right = *max_element(nums.begin(), nums.end());
        int res = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (calc(mid) <= threshold) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return res;
    }
};
