class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals based on the end time (interval[1])
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];  // Sort by the second element (end time)
        });

        int overlapCount = 0;
        int maxY = intervals[0][1];  // Keep track of the end of the last added interval
        
        for (int i = 1; i < intervals.size(); i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];
            
            if (x < maxY) {
                // Overlap occurs, increment the count
                overlapCount++;
            } else {
                // No overlap, update maxY to the end of the current interval
                maxY = y;
            }
        }
        return overlapCount;
    }
};
