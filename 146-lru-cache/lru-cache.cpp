class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    list<int> dd;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    int get(int key) {
        if(!mp.count(key)) return -1;
        dd.erase(mp[key].first);
        dd.push_front(key);
        mp[key].first = dd.begin();
        return mp[key].second;
    }
    void put(int key, int value) {
        if(mp.count(key)){
            dd.erase(mp[key].first);
        } else if(dd.size() == size){
            int todel = dd.back();
            dd.pop_back();
            mp.erase(todel);
        }
        dd.push_front(key);
        mp[key] = {dd.begin(), value};
    }
};

/**
 * Your LRUCache object will be indqantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */