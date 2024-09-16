class Solution {
public:
    void convertInMinutes(vector<string>& timePoints, vector<int>& minutes) {
        for(int i = 0 ; i < minutes.size() ; i++){
            int hours = stoi(timePoints[i].substr(0,2));
            int minute = stoi(timePoints[i].substr(3));
            hours*=60;
            hours+=minute;
            minutes[i] = hours;
        }
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes(timePoints.size());
        convertInMinutes(timePoints,minutes);
        int n = timePoints.size();
        sort(minutes.begin(), minutes.end());
        for(auto it : minutes){
            cout<<it<<" ";
        }
         int minDiff = INT_MAX;

        // Find the minimum difference between consecutive times
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        int wrapAround = (1440 - minutes[n - 1] + minutes[0]); // 1440 minutes in a day
        minDiff = min(minDiff, wrapAround);

        return minDiff;

        
    }
};