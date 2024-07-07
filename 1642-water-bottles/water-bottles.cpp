class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum, rem;
        rem = 0;
        sum = numBottles;
        while(numBottles > 1){
            sum+=numBottles/numExchange;
            if(numBottles/numExchange==0)
            break;
            rem = numBottles % numExchange;
            numBottles/=numExchange;
            numBottles+=rem;
        }
        return sum;
    }
};