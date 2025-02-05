class Solution {
public:
    int countPrimes(int n) {
        // first we do pre-computations on array to find all Prime factors from [1->n) in O(1) time
        // means we use Sieve of Eratosthenes by looping array of n size, & by flaging all multiples of  prime number to false, & always start from the square of that number to do that.

        vector<int> v(n, 1);

        for(int i = 2 ; i <= sqrt(n) ; i++){
            if(v[i]){
                for(int j = i*i ; j < n ; j+=i){
                    v[j] = 0;
                }
            }
        }
        int cnt = 0;
        for(int i = 2 ; i < n ; i++){
            if(v[i]) cnt++;
        }
        return cnt;

        
    }
};