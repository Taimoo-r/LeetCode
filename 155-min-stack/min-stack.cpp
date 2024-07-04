#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    int tp;
    map<int, int> mp;
    vector<int> v;

    MinStack() {
        v.reserve(1000);  // Start with a smaller size, and let it grow dynamically if needed
        tp = -1;
    }

    void push(int val) {
        v.push_back(val);
        tp++;
        mp[val]++;
    }
    
    void pop() {
        if (tp >= 0) {
            int val = v[tp];
            mp[val]--;
            if (mp[val] == 0) {
                mp.erase(val);
            }
            v.pop_back();
            tp--;
        }
    }
    
    int top() {
            return v[tp];
    }
    
    int getMin() {
        return mp.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
