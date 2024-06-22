class BrowserHistory {
public:
    vector<string> h;
    int curr;
    BrowserHistory(string homepage) {
       h.push_back(homepage);
       curr=0;
    }
    
    void visit(string url) {
        h.resize(curr+1);
        h.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        curr-=steps;
        if(curr<0){
            curr = 0;
            return h[0];
        }
        else
        return h[curr];
    }
    
    string forward(int steps) {
        curr+=steps;
        if(curr>h.size()-1)
        {
            curr = h.size()-1;
            return h[h.size()-1];
        }
        else
        return h[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */