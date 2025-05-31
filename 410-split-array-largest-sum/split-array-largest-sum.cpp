class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isValid(mid, nums, k)){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }

    bool isValid(int mid, vector<int> &nums, int k){

        int arr = 1, sum = 0;
        for(auto &it : nums){
            if(sum + it <= mid){
                sum+=it;
            }
            else{
                arr++;
                if(arr > k) return false;
                sum = it;
            }
        }
        return true;
        
    }
};