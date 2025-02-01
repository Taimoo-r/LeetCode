class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto &it : nums){
            string s = to_string(it);
            (s.size()&1)==0 ? cnt++ : cnt;
        }
        return cnt;
    }
};