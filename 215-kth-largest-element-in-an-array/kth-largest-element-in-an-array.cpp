class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0 ; i < k ; i++){
            pq.push(-(nums[i]));
        }
        for(int i = k ; i < nums.size() ; i++){
            if(-(pq.top()) < nums[i]){
                pq.pop();
                pq.push(-nums[i]);
            }
        }
        return -pq.top();
        // nth_element(nums.begin(), nums.begin() + (nums.size() - k), nums.end());
        // return nums[nums.size() - k];
    }
};