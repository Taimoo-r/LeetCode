class Solution {
public:
    double average(vector<int>& salary) {
        double res = 0;
        int i;
        sort(salary.begin(),salary.end());
        for(i=1;i<salary.size()-1;i++){
            res+=salary[i];
        }
        return (res/--i);
    }
};