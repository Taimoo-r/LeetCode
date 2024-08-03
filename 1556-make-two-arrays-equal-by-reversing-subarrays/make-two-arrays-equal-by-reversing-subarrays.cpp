#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size() != arr.size()) {
            return false;
        }
        
        unordered_map<int, int> countMap;
        
        for(int i = 0; i < target.size(); ++i) {
            countMap[target[i]]++;
            countMap[arr[i]]--;
        }
        
        for(auto& count : countMap) {
            if(count.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};
