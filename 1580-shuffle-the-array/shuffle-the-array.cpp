class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> a(nums.size());
        int u=0;
        for(int i=0;i<nums.size()/2;i++){
            a[u]=nums[i];
            u+=2;
        }
        u=1;
        for(int i=n;i<n*2;i++){
            a[u]=nums[i];
            u+=2;
        }
        return a;
    
    }
};