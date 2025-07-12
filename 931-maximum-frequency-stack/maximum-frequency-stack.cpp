class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> freqStack;
    int maxF = 0;
    
    FreqStack() {

    }
    
    void push(int val) {
        freq[val]++;
        int placeToPush = freq[val];
        maxF = max(placeToPush, maxF);
        freqStack[placeToPush].push(val);
    }
    
    int pop() {
        int val = freqStack[maxF].top();
        freqStack[maxF].pop();
        freq[val]--;
        if(freqStack[maxF].empty()) maxF--;
        return val;


    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */