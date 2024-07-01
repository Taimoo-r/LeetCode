class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> temp;
        if(n==1)
        return intervals;
        temp = intervals[0];
        for(int i = 1; i < n ; i++){
            if(temp[1]>=intervals[i][0]){
                temp[1] = max(temp[1],intervals[i][1]);
            }else{
                res.push_back(temp);
                temp = intervals[i];
            }
        }
        res.push_back(temp);
        return res;
        
    }
};