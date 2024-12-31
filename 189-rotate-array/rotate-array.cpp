class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> d(nums.begin(), nums.end());
        while(k--){
            d.push_front(d[n-1]);
            d.pop_back();
        }
        nums.assign(d.begin(), d.end());
        
    }
};