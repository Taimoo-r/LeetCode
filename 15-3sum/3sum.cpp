class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        set<vector<int>> res;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int a = nums[i];
            for(int j = i+1, k = n-1 ; j < k ;){
                int b = nums[j];
                int c = nums[k];
                if((a+b+c) == 0){
                    res.insert({a, b, c});
                    j++, k--;
                }
                else if(a+b+c < 0) j++;
                else k--;
            }
        }
        for(auto &it : res) ans.push_back(it);
        return ans;
    }
};