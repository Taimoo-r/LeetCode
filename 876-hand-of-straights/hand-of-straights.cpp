class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gSize) {
        if (hand.size() % gSize != 0) return false;

        map<int, int> mp;
        for(int x : hand) mp[x]++;

        while(!mp.empty()){
            int top = mp.begin()->first;
            for(int i = 0 ; i < gSize ; i++){
                if(mp[top+i] == 0) return false;
                mp[top+i]--;

                if(mp[top+i] < 1) mp.erase(top+i);
            }
        }

        return true;
    }
};