class Solution {
public:
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long sum = 0;
        for(auto & it : nums) sum+=it;
        if(sum%k!=0) return false;
        vector<bool> used(nums.size(), false);
        sort(nums.rbegin(), nums.rend());

        return help(nums, k, sum/k, 0, 0, used);
    }

    bool help(vector<int> &nums, int k, int sum, int i, int currSum, vector<bool>& used){
        if(k == 1) return true;
        if(currSum == sum){
            return help(nums, k-1, sum, 0, 0, used);
        }

        if(currSum > sum) return false;

        for(int j = i ; j < nums.size() ; j++){
            if(used[j]) continue;
            used[j] = true;
            if(help(nums, k, sum, j+1, currSum+nums[j], used)) return true;
            used[j] = false;
            if (currSum == 0) return false;
        }
        return false;
    }
};

