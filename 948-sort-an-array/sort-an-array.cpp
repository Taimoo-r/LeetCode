class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        split(nums, 0, nums.size()-1);
        return nums;
    }

    void merge(vector<int> &nums, int left, int mid, int right){
        vector<int> temp;
        int i = left,  j = mid+1;
        while(i <= mid && j <= right){
            if(nums[i]<= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while( i <= mid) temp.push_back(nums[i++]);
        while( j <= right) temp.push_back(nums[j++]);
        int k = 0;
        for(int u = left ; u <= right ; u++){
            nums[u] = temp[k++];
        }



    }

    void split(vector<int> &nums, int left, int right){
        if(left >= right) return;

        int mid = left + (right - left)/2;
        split(nums, left, mid);
        split(nums, mid+1, right);
        merge(nums, left, mid, right);
    }

    
};