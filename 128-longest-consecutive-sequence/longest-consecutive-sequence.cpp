class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        set<int> s(nums.begin(),nums.end());
        int longest = 0;
        for(const int& n : s){
            
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

        
        // int n = nums.size();
        // if(n < 1) return 0;
        // int consCnt = 1;
        // int maxCnt = 0;
        // sort(nums.begin(), nums.end());
        // for(int i = 0 ; i < n - 1 ; i++){
        //     if(nums[i+1]==nums[i]) continue;

        //     if(nums[i+1]-nums[i]==1) consCnt++;

        //     else if(nums[i+1] - nums[i]!=1){
        //         maxCnt = max(maxCnt, consCnt);
        //         consCnt = 1;
        //     }
        // }
        // maxCnt = max(maxCnt, consCnt);
        // return maxCnt;
    }
    
};