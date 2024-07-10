class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cus) {
        int n = cus.size();
        double avgTime = 0;
        int prev = 0 ;

        for(int i = 0 ; i < n ; i++){
            int arriveTime = cus[i][0];
            int cookTime = cus[i][1];
            if(arriveTime < prev){
                avgTime += (prev - arriveTime + cookTime); 
                prev+=cookTime;
            }
            else{
                avgTime+=cookTime;
                prev = arriveTime + cookTime;
            }
        }
        return avgTime/n;
    }
};