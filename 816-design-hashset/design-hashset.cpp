class MyHashSet {
public:
    vector<int> v;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(v.begin(),v.end(),key)==v.end())
        v.push_back(key);
    }
    
    void remove(int key) {
        auto it =find(v.begin(),v.end(),key);
        if(it!=v.end())
        v.erase(it);
    }
    bool contains(int key) {
        auto it = find(v.begin(),v.end(),key);
        return it != v.end();
        
        // for(int i = 0 ; i < v.size() ; i++){
        //     if(v[i]==key)
        //         return true;
        // }
        // return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */