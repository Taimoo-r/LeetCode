class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;

        bool sign = true;
        if((dividend <= 0 && divisor > 0) || ( dividend > 0 && divisor < 0 )) sign = false;

        long dend = abs((long)dividend);
        long sor = abs((long)divisor);

        long ans = 0;
        int cnt = 0;
        while(dend>=sor){
            cnt = 0;
            while(dend >= sor<<(1+cnt))
                cnt++;
            ans+=1<<cnt;
            dend-=(sor<<cnt);
        }
        if(ans == 1<<31 && sign) return INT_MAX;
        if(ans == 1<<31 && !sign) return INT_MIN;
        return sign ? ans : ans*-1;


    }
};