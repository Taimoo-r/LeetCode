class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<tuple<int, int, int>> uniq;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n - 2 ; i++){
        int j = i+1, k = n - 1;
            while(j < k){
                if(nums[i]+nums[j]+nums[k] > 0)
                    k--;
                else if(nums[i]+nums[j]+nums[k] < 0)
                    j++;
                else{
                    if(uniq.find({nums[i], nums[j], nums[k]})==uniq.end())
                    res.push_back({nums[i], nums[j], nums[k]});
                    uniq.insert({nums[i], nums[j], nums[k]});
                        k--;
                        j++;
                    }
            }
        }
        return res;
       
    }
};