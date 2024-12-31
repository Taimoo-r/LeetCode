class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
       map<int, int> z;
       int n = nums.size();
       for(int i = 0 ; i < n ; i++){
            if(nums[i]==0)
                z[0]++;
       }
       for(int i = 0 ; i < n ; i++){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                n--;
                i--;
            }
       }
       nums.insert(nums.end(), z[0], 0);
    }
};