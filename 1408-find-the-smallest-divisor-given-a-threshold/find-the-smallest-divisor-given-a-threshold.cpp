class Solution {
public:

    int calc(vector<int>& nums, int mid){
        int result = 0;
        for(auto &it : nums){
            result += ceil((it*1.0)/mid);
        }
        return result;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6;
        int res = 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(calc(nums, mid) <= threshold){
                right = mid - 1 ;
                res = mid;
            }
            else
                left = mid + 1;
        }
        return res;
    }
};