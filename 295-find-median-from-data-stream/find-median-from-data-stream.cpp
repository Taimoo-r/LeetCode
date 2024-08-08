class MedianFinder {
public:
    priority_queue<int> max;
    priority_queue<int, vector<int>,greater<int>> min;
    MedianFinder() {
    }
    
    void addNum(int num) {
        max.push(num);
        if(!min.empty() && max.top() > min.top()){
            min.push(max.top());
            max.pop();
        }
        if(max.size() > min.size()+1){
        min.push(max.top());
        max.pop();
        }
        if(min.size() > max.size()){
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
        if(max.size() > min.size()){
            return (double)max.top();
        }
        else{
            return (min.top()+max.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */