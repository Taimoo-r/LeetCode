class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target==arr)
            return true;
        unordered_map<int,int> m1,m2;
        for(int i = 0 ; i < target.size(); i++){
            m1[target[i]]++;
            m2[arr[i]]++;
        }
        return m1==m2 ? true : false;
        
    }
};