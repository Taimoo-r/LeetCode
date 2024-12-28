class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int min_closest = INT_MAX;
        int ans_sum = 0;
        for(int i = 0 ; i < n ; i++){
            int curr = nums[i];
            int st = i + 1, ed = n - 1;
            bool handle = true;
            while(st < ed){
                int closest;
                int find = curr + nums[st] + nums[ed];
                if(find > t) ed--;
                else if(find < t) st++;
                else if(find == t) handle = false;
                closest = abs(find - t);
                    if(min_closest > closest){
                        min_closest = closest;
                        ans_sum = find;
                    }
                if(!handle) break;
            }
        }
        return ans_sum;
    }
};