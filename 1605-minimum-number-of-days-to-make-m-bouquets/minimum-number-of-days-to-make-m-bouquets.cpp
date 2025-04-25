class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0;
        for(auto &it : bloomDay){
            if(day >= it){
                cnt++;
            }
            else{
                m-=(cnt/k);
                cnt = 0;
            }
        }
        m-=(cnt/k);
        return m <= 0 ? true : false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k) return -1;
        int ans = -1;
        int n = bloomDay.size();
        int start = *min_element(bloomDay.begin(), bloomDay.end()), end =*max_element(bloomDay.begin(), bloomDay.end());
        while(start <= end){
            int mid = start + (end - start)/2;
            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid+1;
        }
        return ans;
        
    }
};