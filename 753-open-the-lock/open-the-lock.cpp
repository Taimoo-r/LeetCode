#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;  // cannot start

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({"0000", 0});
        visited.insert("0000");

        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();

            if (cur == target) return steps; // found it!

            for (auto &next : getNextStates(cur)) {
                if (!dead.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }

        return -1; // impossible
    }

private:
    vector<string> getNextStates(string s) {
        vector<string> res;
        for (int i = 0; i < 4; ++i) {
            string up = s, down = s;
            up[i]   = (s[i] - '0' + 1) % 10 + '0';
            down[i] = (s[i] - '0' + 9) % 10 + '0';
            res.push_back(up);
            res.push_back(down);
        }
        return res;
    }
};
