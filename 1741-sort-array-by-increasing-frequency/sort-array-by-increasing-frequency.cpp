class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        map<int,vector<int>> fre;
        for(auto it : mp){
            fre[it.second].push_back(it.first);
        }
        nums.clear();
        for(auto it : fre){
            int size = it.second.size();
            while(size--){
                int count = it.first;
                while(count--){
                    nums.push_back(it.second[size]);
                }
            }
        }
        return nums;
    }
};