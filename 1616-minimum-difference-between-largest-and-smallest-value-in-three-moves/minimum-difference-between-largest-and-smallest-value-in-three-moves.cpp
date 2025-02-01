class Solution {
public:
    int minDifference(vector<int>& n) {
        if(n.size() <= 4)
            return 0;
        sort(n.begin(), n.end());
        int s = n.size();

        return min({n[s-4] - n[0], n[s-3] - n[1], n[s-2] - n[2], n[s-1] - n[3]});
        
    }
};