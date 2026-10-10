class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3, 0);
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) v[nums[i]]++;
        int j = 0;
        for(int i = 0 ; i < n ; i++){
            while(v[j]==0) j++;
            nums[i] = j;
            v[j]--;
        }
        
    }
};