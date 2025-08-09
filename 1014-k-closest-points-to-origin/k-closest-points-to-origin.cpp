

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        // <int, vector<int> , comp>;

        for(auto &it : points){
            pq.push({(pow(it[0],2)+pow(it[1], 2)), {it[0], it[1]}});

            if(pq.size() > k){
                pq.pop();
            }
        }

        


        vector<vector<int>> ans;

        while(!pq.empty()){
            auto [a, b] = pq.top().second;
            ans.push_back({a, b});
            pq.pop();
        }
        return ans;


    }
};


struct comp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return abs(a.first + a.second) < abs(b.first + b.second);
    }
};

// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

//         for(int i = 0 ; i < k ; i++){
//             pq.push({points[i][0], points[i][1]});
//         }

//         for(int i = k ; i < points.size() ; i++){
//             int a = points[i][0];
//             int b = points[i][1];
//             auto [x, y] = pq.top();
//             if(abs(a + b) < abs(x+y)){
//                 pq.pop();
//                 pq.push({a, b});
//             }
//         }

//         vector<vector<int>> ans;

//         while(!pq.empty()){
//             auto [a, b] = pq.top();
//             ans.push_back({a, b});
//             pq.pop();
//         }
//         return ans;


//     }
// };