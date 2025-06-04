class Solution {
public:
    const int MOD = 1e9 + 7;

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long res = (power(5, evenPositions) * power(4, oddPositions)) % MOD;
        return (int)res;
    }

    long long power(long long a, long long b) {
        long long result = 1;
        a %= MOD;

        while (b > 0) {
            if (b & 1) {
                result = (result * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }
};
