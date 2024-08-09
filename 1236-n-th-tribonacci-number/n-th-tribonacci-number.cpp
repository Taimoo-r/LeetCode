class Solution {
public:
    int tribonacci(int n) {
        map<long,long> mp;
        return healper(n,mp);
    }
    long long healper(long long n, map<long,long> &mp){
        if(mp.find(n)!=mp.end())
        return mp[n];
        if(n<=0)
        return 0;
        if(n<2)
        return 1;
        mp[n] = healper(n-1,mp) + healper(n-2,mp) + healper(n-3,mp);
        return mp[n];
    }
};