class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int curr = 1, maxi = 0;
        
        // Looping over 'st' instead of 'nums' automatically filters duplicates
        for(const int &x : st){ 
            if(!st.count(x-1)){
                int c = x;
                curr = 1;
                while(st.count(c+1)){
                    c++;
                    curr++;
                }
                maxi = max(maxi, curr);
            }
        }
        return maxi;
    }
};
