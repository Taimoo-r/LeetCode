class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false;

        map<int, int> mp;
        for(auto &x : nums) mp[x]++;

        while(!mp.empty()){
            int e = mp.begin()->first;
            for(int i = 0 ; i < k ; i++){
                if(mp[e+i] == 0) return false;
                mp[e+i]--; 
                if(mp[e+i] < 1){
                    // cout<<"Erasing : "<<e+i<<endl;
                    mp.erase(e+i);
                }
            }
        }
        return true;
    }
};