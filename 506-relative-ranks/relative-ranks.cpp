class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> scoreIndexPairs;
        
        // Create a vector of pairs (score, index)
        for (int i = 0; i < n; i++) {
            scoreIndexPairs.push_back({score[i], i});
        }
        
        // Sort the pairs in descending order based on the scores
        sort(scoreIndexPairs.rbegin(), scoreIndexPairs.rend());
        
        vector<string> ans(n);
        
        // Assign ranks based on the sorted order
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[scoreIndexPairs[i].second] = "Gold Medal";
            } else if (i == 1) {
                ans[scoreIndexPairs[i].second] = "Silver Medal";
            } else if (i == 2) {
                ans[scoreIndexPairs[i].second] = "Bronze Medal";
            } else {
                ans[scoreIndexPairs[i].second] = to_string(i + 1);
            }
        }
        
        return ans;
    }
};
