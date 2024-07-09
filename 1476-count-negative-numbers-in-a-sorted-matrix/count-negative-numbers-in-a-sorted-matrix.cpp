class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    //     int n = 0;
    // for(auto g : grid){
        
    //     for(int i = g.size()-1; i > -1 ; i--){
    //         if(g[i]<0)
    //         n++;
    //         else
    //         break;
    //     }
    // }
    // return n;
        int ans = 0;
        for(auto& row : grid) {
            int left = 0, right = row.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (row[mid] < 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans += row.size() - left; // All elements from `left` to end are negative
        }
        return ans;
    }
};

        