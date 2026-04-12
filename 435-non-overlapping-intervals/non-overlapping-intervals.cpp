class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end()); // sort by start time
        
        int cnt = 0;
        int prevEnd = in[0][1];
        
        for(int i = 1; i < in.size(); i++){
            int start = in[i][0];
            int end = in[i][1];
            
            if(start < prevEnd){
                // overlap → remove one interval
                cnt++;
                
                // keep the one with smaller end (your idea)
                prevEnd = min(prevEnd, end);
            } else {
                // no overlap
                prevEnd = end;
            }
        }
        
        return cnt;
    }
};