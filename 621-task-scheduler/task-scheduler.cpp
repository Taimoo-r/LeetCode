struct cmp{
    bool operator()(pair<char, int> a, pair<char, int> b){
        return a.second < b.second; 
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto &it: tasks) mp[it]++;
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        for(auto &[e, f]: mp) pq.push({e, f});
        auto [e, f] = pq.top(); pq.pop();
        // cout<<e<<" "<<f;
        int t = f;
        int I = (f - 1)*n;
        while(!pq.empty()){
            auto [k, o] = pq.top(); pq.pop();
            // cout<<"\n"<<k<<" "<<o;
            I-=(o > t-1 ? t-1 : o);
            // cout<<" I = "<<I<<endl;
        }
        I=max(I,0);
        return I+tasks.size();
    }
};