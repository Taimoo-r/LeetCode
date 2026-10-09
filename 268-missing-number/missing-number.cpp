class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = (n*(1+n))/2;
        int csum = 0;
        for(auto &it : nums){
            csum+=it;
        }
        cout<<sum<<" "<<csum;
        return sum-csum;
    }
};