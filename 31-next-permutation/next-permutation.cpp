class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // vector<int> v;
        // v = nums;
        // sort(v.begin(), v.end());
        // int cnt = 0;
        // bool found = false;
        // do{
        //     vector<int> check;
        //     for (int i : v) 
        //         check.push_back(i);
        //     if(check==nums){
        //         found = true;
        //         continue;
        //     }
        //     if(found){
        //         cnt++;
        //         nums = check;
        //         break;
        //     }
        // } while (next_permutation(v.begin(), v.end()));
        // if(!cnt)
        //     sort(nums.begin(), nums.end());
        int n = nums.size();
        int bp = -1;
        for(int i = n - 2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1]){
                bp = i;
                break;
            }
        }
        if(bp!=-1){
            for(int i = n - 1 ; i > bp ; i--){
                if(nums[i]>nums[bp]){
                    swap(nums[i], nums[bp]);
                    break;
                }
            }
            reverse(nums.begin()+bp+1, nums.end());
        }
        else{
            sort(nums.begin(), nums.end());
        }
    }
};