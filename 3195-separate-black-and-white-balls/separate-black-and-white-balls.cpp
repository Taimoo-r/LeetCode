class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long swapCount = 0;

        int end = n - 1;
        for(int i = n - 1 ; i >-1 ; i--){
            if(s[i]=='1'){
                swapCount+= end - i;
                end--;
            }
        }
        return swapCount;
    }
};