class Solution {
public:

    bool possible(vector<int>& weights, int capacity, int days){
        
        int sum = 0;
        for(auto &it : weights){
            if(sum+it <= capacity){
                sum+=it;
            }
            else{
                days--;
                sum = it;
            }

            if(days==0) return false;
        }
        return days > 0 ? true : false;

    }

    int shipWithinDays(vector<int>& weights, int days) {

        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0); 
        int ans = start;
        while(start <= end){
            int mid = start + (end - start)/2;

            cout<<mid<<" ";

            if(possible(weights, mid, days)){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid+1;
        }
        return ans;


        
    }
};