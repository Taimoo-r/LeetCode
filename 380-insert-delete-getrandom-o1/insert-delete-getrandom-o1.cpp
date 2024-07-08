class RandomizedSet {
public:
    vector<int> v;
    map<int, int> mp;

    RandomizedSet() {
        // srand(time(0));
    }

    bool insert(int val) {
        if (mp.find(val) == mp.end()) {
            v.push_back(val);
            mp[val] = v.size() - 1;
            return true;
        } else
            return false;
    }

    bool remove(int val) {
        if (mp.find(val) != mp.end()) {
           int index = mp[val];
           int lastValue = v.back();
           v[index] = lastValue;
           mp[lastValue] = index;
           v.pop_back();
           mp.erase(val);
            return true;
        } else {
            return false;
        }
    }
    int getRandom() {
        int randomIndex = rand() % v.size(); 
        return v[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */