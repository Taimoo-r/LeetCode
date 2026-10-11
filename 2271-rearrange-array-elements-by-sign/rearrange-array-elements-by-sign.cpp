class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p, n;
        for(auto &x : nums){
            if(x > 0) p.push_back(x);
            else n.push_back(x);
        }
        int j = 0, k = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i%2==0) nums[i] = p[j++];
            else nums[i] = n[k++];
        }
        return nums;
    }
};