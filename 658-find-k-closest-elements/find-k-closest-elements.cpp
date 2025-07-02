class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // set<int> st(arr.begin(), arr.end());
        // int n = arr.size();
        // vector<int> ans(k);
        // int maxDiff = 0;
        // int r = 0, l = 0;
        // for(r ; r < k ; r++){
        //     maxDiff = max(abs(x - arr[r]), maxDiff);
        //     ans[r] = arr[r];
        // }
        // for(r ; r < n ; r++){
        //     while(r - l >= k){
        //         maxDiff = max(abs(maxDiff - arr[l]), maxDiff);
        //         l++;
        //     }
        //     int currDiff = 0;
        //     if(arr[r] > x){
        //         currDiff = max(arr[r] - x, abs(arr[l] - x));
        //     } else if(arr[r] < x){
        //         currDiff = abs(x - arr[l]);
        //     }

        //     if(maxDiff > currDiff){
        //         for(int i = 0 ; i <= r-l ; i++){
        //             ans[i] = arr[l+i];
        //         }
        //         for(auto &it : ans) cout<<it<<" ";
        //         cout<<endl;
        //     }
        // }
        // return ans;   
        priority_queue<pair<int, int>> pq;
        for(auto &it : arr){
            pq.push({abs(it - x), it});
            while(pq.size() > k) pq.pop();
        }
        vector<int> ans(k);
        for(auto &it : ans){
            it = pq.top().second;
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans; 
        
    }
};