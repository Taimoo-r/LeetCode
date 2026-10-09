class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> st;
        int j =0;
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(!st.count(nums[i])){
                st.insert(nums[i]);
                nums[j++] = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};