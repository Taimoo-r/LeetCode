class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end(), [](auto &a, auto &b){
            return a[1] < b[1]; // sort by end time
        });

        int cnt = 0;
        int prevEnd = in[0][1];

        for(int i = 1; i < in.size(); i++){
            if(in[i][0] < prevEnd){
                // overlap → remove this interval
                cnt++;
            } else {
                // no overlap → update prevEnd
                prevEnd = in[i][1];
            }
        }

        return cnt;
    }
};