class Solution {
public:
    
    int f(int n, vector<int>& v){
        if(v[n]!=-1) return v[n];
        if(n == 0) return 0;
        if(n == 1) return 1;
        v[n] = f(n-1, v)+f(n-2, v);
        return v[n];

    }
    int fib(int n) {
        vector<int> v(n+1, -1);
        return f(n, v);
    }
};
