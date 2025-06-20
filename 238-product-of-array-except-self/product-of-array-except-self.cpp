class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();;
        vector<int> p(n, 1),s(n, 1),ans(n);
        s[n-1] = nums[n-1];
        p[0] = nums[0]; 

        for(int i = 1, j = n-2 ; i < n ; i++){
            p[i]=p[i-1]*nums[i];
            s[j]=s[j+1]*nums[j];
            j--;
        }
        ans[0] = s[1];
        ans[n-1] = p[n-2];
        for(int i = 1 ; i < n-1 ; i++){
            ans[i] = p[i-1]*s[i+1];
        }
        return ans;
        
    }
};