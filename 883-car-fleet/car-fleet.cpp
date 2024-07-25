class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        priority_queue<vector<double>> pq;
        int fleet = 0;
             for (int i = 0; i < pos.size(); i++) {
             double time = (double)(target - pos[i]) / speed[i];
             pq.push({(double)pos[i], (double)speed[i], time});
        }
        while(true){
            if(pq.size()==1){
                return ++fleet;
            }
            auto ahead = pq.top(); pq.pop();
            auto behind = pq.top(); pq.pop();
            if(ahead[2]>=behind[2]){
                pq.push(ahead);
            }
            else if(ahead[2] <= behind[2]){
                fleet++;
                pq.push(behind);
            }
        }
    }
};