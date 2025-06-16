class MyHashSet {
public:
    vector<bool> v;

    MyHashSet() {
        v = vector<bool>(1000001, false); // Step 1: Initialization
    }

    void add(int key) {
        v[key] = true; // Step 2: Mark presence
    }

    void remove(int key) {
        v[key] = false; // Step 3: Mark absence
    }

    bool contains(int key) {
        return v[key]; // Step 4: Check presence
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */