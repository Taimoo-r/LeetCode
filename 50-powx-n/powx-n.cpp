class Solution {
public:
    double calc(double x, long n){
        if(n==0) return 1;
        if(n < 0) return calc(1/x, -n);
        if(n%2==0) return calc(x*x, n/2);
        else return x*calc(x*x, (n - 1)/2);
    }
    double myPow(double x, int n) {
        return calc(x, n);
    }
};