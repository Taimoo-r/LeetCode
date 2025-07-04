class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        // pair -> {num, index}
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});

            // Only start recording answers after window is full
            if (i >= k - 1) {
                // Remove elements that are outside the window
                while (pq.top().second <= i - k) {
                    pq.pop();
                }

                // Top is max of current window
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};
