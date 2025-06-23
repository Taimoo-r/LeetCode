class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int s = nums.size();
        vector<bool> v(1e5+2, false);
        for(auto &n : nums){
            if(n >= 0){
                v[n%(100000+2)] = true;
            }
        }
        v[0] = true;
        for(int i = 0 ; i < s+2 ; i++){
            if(v[i] == false) return i;
        }
        return 1;

        
        
    }
};