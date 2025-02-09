class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            bool f = false;
            for(int j = i+1 ; (j%n)!=i ; j++){
                if(nums[j%n] > nums[i]){
                    ans.push_back(nums[j%n]);
                    f = 1;
                    break;
                }
            }
            if(!f) ans.push_back(-1);
        }
        return ans;
    }
};