class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto &it : tasks) mp[it]++;

        priority_queue<int> pq;

        for(auto [a, b] : mp) pq.push(b);

        int time = 0;
        while(!pq.empty()){
            int coolDownCycle = n +1;//because you can't do t + n, it should be t+n+1 so that there is 
            // atleast n gap between two occurences of same task
            vector<int> v;
            while(coolDownCycle > 0 && !pq.empty()){
                int count = 0;
                if(!pq.empty()){
                    count = pq.top();
                    pq.pop();
                }
                if(count - 1 > 0) v.push_back(count -1);
                coolDownCycle--;
                time++;
            }

            for(auto &it : v){
                pq.push(it);
            }

            if(!pq.empty()) time+=coolDownCycle;
        }
        return time;
    }
};