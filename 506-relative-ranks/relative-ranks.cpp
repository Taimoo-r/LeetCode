class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        int count = 0;
        priority_queue<int> pq(score.begin(),score.end());
        for(int i = 0 ; i < score.size() && !pq.empty(); i++){
            for(int j = 0 ; j < score.size(); j++){
                if(pq.top()==score[j]){
                    count++;
                    if(count==1)
                    ans[j] = "Gold Medal";
                    else if(count==2)
                    ans[j] = "Silver Medal";
                    else if(count==3)
                    ans[j] = "Bronze Medal";
                    else
                    ans[j] = to_string(count);
                    pq.pop();
                }
            }
        }
        return ans;
        
    }
};