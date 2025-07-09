class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
       vector<pair<int, double>> v(pos.size());
       int n = speed.size();
       for(int i = 0 ; i < n ; i++){
        v[i] = {pos[i], (double)(target - pos[i])/speed[i]};
 
       }


       sort(v.rbegin(), v.rend());
       
      stack<double> st;

       for(auto &[__, time] : v){
         if (st.empty() || time > st.top()) {
                st.push(time);
            }
    }
        return st.size();
    }
    

};