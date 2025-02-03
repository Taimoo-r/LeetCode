class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int incLen, decLen;
        int Icnt = 1, Dcnt = 1;
        for(int i = 0 ; i < n - 1 ; i++){
            if(nums[i] < nums[i+1]){
                Icnt++;
                decLen = max(decLen, Dcnt);
                Dcnt = 1;
            }
            else if(nums[i] > nums[i+1]){
                Dcnt++;
                incLen = max(incLen, Icnt);
                Icnt = 1;
            }
            else{
                incLen = max(incLen, Icnt);
                decLen = max(decLen, Dcnt);
                Icnt = Dcnt =  1;
            }
        }

        return max({incLen, decLen, Icnt, Dcnt});
    }
};