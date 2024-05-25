class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highAltitude = gain[0];
        for (int i = 0; i < gain.size()-1; i++) {
            gain[i] + gain[i + 1] > highAltitude ? highAltitude = gain[i] + gain[i + 1] : highAltitude;
            gain[i + 1] = gain[i] + gain[i + 1];
        }
        if (highAltitude > 0)
            return highAltitude;
        else
            return 0;
    }
};