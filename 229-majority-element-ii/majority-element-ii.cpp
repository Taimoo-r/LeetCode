class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int a = INT_MIN, b = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(c1 == 0 && nums[i] != b) {
                c1 = 1;
                a = nums[i]; 
            }
            else if(c2 == 0 && nums[i] != a) {
                c2 = 1;
                b = nums[i];
            }
            else if(a == nums[i]) c1++;
            else if(b == nums[i]) c2++;
            else {
                c1--;
                c2--;
            }
        }
        c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == a) c1++;
            else if(nums[i] == b) c2++;
        }
        vector<int> ans;
        int mini = (int)(n/3) + 1;
        if(c1 >= mini) ans.push_back(a);
        if(c2 >= mini) ans.push_back(b);
        sort(ans.begin(), ans.end());
        return ans;
    }
};