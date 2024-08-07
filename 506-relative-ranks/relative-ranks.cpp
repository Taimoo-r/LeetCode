class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int,int> mp;
        for(int i = 0 ; i < score.size() ; i++){
            mp[score[i]] = i;
        }
        priority_queue<int> pq(score.begin(),score.end());
        vector<string> ans(score.size());
        int c = 0;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            c++;
            if(c==1)
            ans[mp[top]] = "Gold Medal";
            else if(c==2)
            ans[mp[top]] = "Silver Medal";
            else if(c==3)
            ans[mp[top]] = "Bronze Medal";
            else
            ans[mp[top]] = to_string(c);
        }
        return ans;

        
    }
};