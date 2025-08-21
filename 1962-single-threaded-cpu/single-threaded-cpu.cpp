struct Item {
    int pTime;
    int index;
    int enqTime;
    Item(int p, int idx, int enq) : pTime(p), index(idx), enqTime(enq) {}
};

struct Comparator {
    bool operator()(const Item& a, const Item& b) const {
        if (a.pTime != b.pTime) return a.pTime > b.pTime; // smaller pTime first
        return a.index > b.index;                         // smaller index first
    }
};


class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int, 3>> sorted; // {enqTime, pTime, index}
        for (int i = 0; i < n; i++) {
            sorted.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(sorted.begin(), sorted.end()); // sort by enqTime

        priority_queue<Item, vector<Item>, Comparator> pq;
        vector<int> order;
        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {
            if (pq.empty() && time < sorted[i][0]) {
                time = sorted[i][0]; // jump forward if CPU idle
            }

            // push all tasks that have arrived
            while (i < n && sorted[i][0] <= time) {
                pq.push(Item(sorted[i][1], sorted[i][2], sorted[i][0]));
                i++;
            }

            // run the next task
            auto task = pq.top(); pq.pop();
            time += task.pTime;
            order.push_back(task.index);
        }
        return order;
    }
};
