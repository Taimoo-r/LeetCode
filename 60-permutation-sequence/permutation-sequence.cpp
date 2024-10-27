class Solution {
public:
    string getPermutation(int n, int k) {
    //     vector<int> v(n);
    //     for(int i = 0 ; i < n ; i++){
    //         v[i] = i+1;
    //     }
    //     sort(v.begin(), v.end());
    //     int i = 0;
    //     string ans = "";
    // do {
    //     for (int &num : v) {
    //         if(i == k - 1){
    //             ans+= '0'+num;
    //         }
    //     }
    //     i++;
    // } while (std::next_permutation(v.begin(), v.end()) && i < k);

    // return ans;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        
        vector<string> res;
        vector<int> visit(n, 0);
        string temp = "";
        helper(nums, visit, temp, res, k);
        return res[k - 1];
    }
    
    void helper(vector<int>& nums, vector<int>& visit, string& temp, vector<string>& res, int k) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (!visit[i]) {
                visit[i] = 1; // Mark as visited
                temp += to_string(nums[i]); // Append current number as a string
                
                // Stop if we've collected enough permutations
                if (res.size() < k) {
                    helper(nums, visit, temp, res, k);
                }
                
                // Backtrack
                visit[i] = 0; // Unmark as visited
                temp.pop_back(); // Remove last character from temp
            }
        }
    }
};
