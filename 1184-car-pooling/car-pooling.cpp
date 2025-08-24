struct comp{
    bool operator()(const vector<int> &a, const vector<int> &b){
        return a[1] > b[1];
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        unordered_map<int, list<int>> mp;
        for(auto &trip : trips) pq.push(trip);
        int booked = 0;
        int i = 0;
        while(!pq.empty()){
            vector<int> trip = pq.top();

            if (mp.count(i)) {
                for (int cap : mp[i]) booked-= cap;
                mp.erase(i);
            }

            while(!pq.empty() && pq.top()[1] == i){
                vector<int> trip = pq.top(); pq.pop();
                int cap = trip[0], start = trip[1], end = trip[2];
                if(cap+booked > capacity) return false;
                mp[end].push_back(cap);
                booked+=cap;
            }
            i++;
        }
        return true;
    }
};