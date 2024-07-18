class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        int l = 0, r = num.size()-1;
        while( l < r){
            if(num[l]+num[r]==t)
            return {l+1,r+1};
            else if(num[l]+num[r]<t)
            l++;
            else if(num[l]+num[r]>t)
            r--;
        }
        return {0,0};
    }
};
