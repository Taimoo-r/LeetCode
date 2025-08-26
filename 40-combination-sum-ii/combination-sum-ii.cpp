class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    vector<vector<int>> combinationSum2(vector<int>& cand, int t) {
        sort(cand.begin(), cand.end());
        help(cand, t, 0, t);
        return ans;
    }

    void help(vector<int>& cand, int t, int i, int rem){


        if(rem == 0){
            ans.push_back(curr);
            return;
        }

       
        // 1, 1, 2, 5, 6, 7, 10

        for(int j = i ; j < cand.size() ; j++){
            if(cand[j] > rem) break;
            if(j > i && cand[j] == cand[j-1]) continue;

            curr.push_back(cand[j]);
            for(auto &it : curr) cout<<it<<" ";

            help(cand, t, j+1, rem-cand[j]);
            curr.pop_back();
        }
    }

};