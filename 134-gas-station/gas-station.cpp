class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalKamai = accumulate(gas.begin(), gas.end(), 0);
        int totalLagai = accumulate(cost.begin(), cost.end(), 0);
        if(totalKamai < totalLagai) return -1;
        int ans = 0;
        int fuel = 0;
        for(int i = 0 ; i < n ; i++){
            fuel+=gas[i]-cost[i];

            if(fuel < 0){
                ans = i+1;
                fuel = 0;
            }
        }
        return fuel >= 0 ? ans : -1;
    }
};