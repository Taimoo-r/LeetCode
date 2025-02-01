class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto &it : nums){
            if((it >= 10 && it <= 99 )|| (it > 999 && it<=9999) || (it > 99999 && it <= 999999))
                cnt++;
        }
        return cnt;
    }
};