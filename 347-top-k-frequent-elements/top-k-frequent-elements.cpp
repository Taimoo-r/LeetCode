class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        map<int, int> mp;
        for(int i = 0 ; i < nums.size() ; i++) {
            mp[nums[i]]++;  
        }
        for(auto &[num, freq]: mp){
            pq.push({-freq,num});
            if(pq.size() > k) pq.pop();
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};