class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;

        priority_queue<pair<int, char>> pq;
        for (auto &[c, f] : mp) pq.push({f, c});

        string ans = "";

        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            ans += a.second;

            if (!pq.empty()) {
                auto b = pq.top(); pq.pop();
                ans += b.second;

                if (a.first - 1 > 0) pq.push({a.first - 1, a.second});
                if (b.first - 1 > 0) pq.push({b.first - 1, b.second});
            } else {
                // only one left → must check if it can be placed
                if (a.first - 1 > 0) {
                    // if the last placed char == this one → impossible
                    if (!ans.empty() && ans.back() == a.second) return "";
                    // otherwise place the last leftover
                    ans += string(a.first - 1, a.second);
                }
            }
        }
        return ans;
    }
};
