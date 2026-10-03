class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n = nums.size();
        map<int, vector<int>> mp;
        for(int i = 0 ; i < n ; i++) mp[nums[i]].push_back(i);
        sort(begin(nums), end(nums));
        int i = 0, j = n-1;
        while(i < j){
            if(nums[i]+nums[j] > t) j--;
            else if(nums[i]+nums[j] < t) i++;
            else{
                if(nums[i]==nums[j]){
                    return {(mp[nums[i]])[0], (mp[nums[j]])[1]};
                }else return {mp[nums[i]].back(), mp[nums[j]].back()};
            }
        }
        return {-1, -1};
    }
};