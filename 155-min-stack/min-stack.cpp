class MinStack {
public:
    int tp;
    map<int,int> mp;
    vector<int> v;
    MinStack() {
        v.resize(1000000,0);
        tp =  -1;
    }

    void push(int val) {
        v[++tp] = val;
        mp[val]++;
    }
    
    void pop() {
        mp[v[tp]]--;
        if(mp[v[tp]]==0)
        mp.erase(v[tp]);
        tp--;
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