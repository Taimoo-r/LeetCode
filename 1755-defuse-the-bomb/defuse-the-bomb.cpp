class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
         int sum = 0, j = 1,count;
        vector<int> res(n, 0);
        if (k == 0)
            return res;
        else if (k > 0) {
            for (int i = 0; i < n; i++) {
                count = k;
                sum = 0;
                j = i + 1;
                while(count--){
                    sum+=code[j%n];
                    j++;
                }
                res[i]=sum;
            }
        }
        else{
            for(int i = 0 ; i < n ; i++){
                count = k;
                sum = 0;
                for(int j = 1; j <=-k ; j++){
                    sum+=code[(i - j + n) % n];
                }
                    res[i] = sum;
                }
            }
        return res;
    }
};