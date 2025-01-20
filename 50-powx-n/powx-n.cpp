class Solution {
public:
    double calc(double x, long n){
        if(n==0) return 1;
        double half=calc(x, n/2);
        if(n%2==0) return half*half;
        else return half*half*x;
    }
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        long nn = n;
        if(n < 0)
            nn = -nn;
        else nn = n;
        double ans = calc(x, nn/2);
        if(n%2==0){
            ans*=ans;
        } else{
            ans = ans*ans*x;
        }
        if(n < 0) ans = double(1.0)/ans;

        return ans;
    }
};