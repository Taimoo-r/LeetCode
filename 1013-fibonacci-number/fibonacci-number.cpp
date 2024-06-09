class Solution {
public:
    int Fibo(int x){
        if(x==0)
        return 0;
        else if(x==1)
        return 1;
        return (Fibo(x-1)+Fibo(x-2));
    }
    int fib(int n) {
        return Fibo(n);
    }
};