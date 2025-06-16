class MyHashSet {
public:
    vector<int> v;
    MyHashSet() {
        v.resize(1e6+1, -1);
    }
    
    void add(int key) {
        v[key] = key;
    }
    
    void remove(int key) {
        v[key] = -1;
    }
    
    bool contains(int key) {
        return v[key] != -1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */