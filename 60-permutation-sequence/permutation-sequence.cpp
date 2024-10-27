class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            v[i] = i+1;
        }
        sort(v.begin(), v.end());
        int i = 0;
        string ans = "";
    do {
        for (int &num : v) {
            if(i == k - 1){
                ans+= '0'+num;
            }
        }
        i++;
    } while (std::next_permutation(v.begin(), v.end()) && i < k);

    return ans;

        // vector<vector<int>> res;
        // vector<int> temp;
        // vector<int> nums(n);
        // for(int i = 0 ; i < n ; i++){
        //     nums[i] = i+1;
        // }
        // vector<int> visit(nums.size(), 0);
        // for(int i = 0 ; i < nums.size() ; i++){
        //     if(!visit[i]){
        //         helper(nums, i, res, visit, temp, k);
        //     }
        // }
        // string ans = "";
        // for(int i = 0 ; i < n ; i++){
        //     ans+='0'+res[k][i];
        // }
        // cout<<ans;
        // return "";
    }
    void helper(vector<int>& nums, int i, vector<vector<int>> &res, vector<int> &visit, vector<int> &temp, int k){
        visit[i] = 1;
        temp.push_back(nums[i]);
        if(res.size()==k) return;
        if(temp.size()==nums.size())
            res.push_back(temp);
        for(int i = 0 ; i < nums.size() ; i++){
            if(!visit[i])
                helper(nums, i, res, visit, temp,k);
        }
        visit[i] = 0;
        temp.pop_back();
    }
};