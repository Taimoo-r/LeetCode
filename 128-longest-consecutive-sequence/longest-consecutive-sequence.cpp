class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        unordered_set<int> s(nums.begin(),nums.end());
        int longest = 0;
        for(const int& n : nums){
            
            if(s.find(n - 1)==s.end()){
                int current = n;
                int currLong = 1;
                while(s.find(current + 1)!=s.end()){
                    current+=1;
                    currLong+=1;
                }
                longest = max(longest,currLong);
            }
        }
        return longest;
    }
    
};