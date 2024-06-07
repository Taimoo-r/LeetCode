class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> seen;
        for (int num : nums) {
            seen[num]++;
        }
        for(auto it : seen){
            if(it.second>=2)
            return true;
        }
        return false;
    }
};