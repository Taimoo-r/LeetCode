class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            v[i] = i+1;
        }
        sort(v.begin(), v.end());
        int i = 0;
        string ans = "";
    do {
        for (int &num : v) {
            if(i == k - 1){
                ans+= '0'+num;
            }
        }
        i++;
    } while (std::next_permutation(v.begin(), v.end()) && i < k);

    return ans;
    }
};