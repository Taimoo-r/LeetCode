class KthLargest {
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto n : nums){
            add(n);
        }
    }
    
    int add(int val) {
        if(pq.size() < k){
            pq.push(-val);
        }
        else if(-pq.top() < val ){
            pq.pop();
            pq.push(-val);
        }
        return -pq.top();
        
        return -pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */