class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int l = 0;
        int r = n - 1;
        int boats = 0;
        while(l <= r){
            if(l == r){
                boats++;
                break;
            }
            int s = people[l];
            int g = people[r];
            if(s+g <= limit){
                l++, r--;
            }
            else r--;
            boats++;
        }
        return boats;

    }
};