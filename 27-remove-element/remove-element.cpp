class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> v = nums;
        int count = 0;
        nums.erase(nums.begin(),nums.end());
        for(int i=0;i<v.size();i++){
            if(v[i]!=val){
                nums.push_back(v[i]);
                count++;
            }

        }
        return count;
    }
};