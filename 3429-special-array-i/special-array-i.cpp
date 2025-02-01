class Solution {
public:
    bool isArraySpecial(vector<int>& a) {
        for(int i = 0 ; i < a.size() - 1 ; i++){
            if(((a[i]&1)==0 && (a[i+1]&1)==0) || ((a[i]&1)!=0 &&  (a[i+1]&1)!=0))
                return false;
        }
        return true;
    }
};