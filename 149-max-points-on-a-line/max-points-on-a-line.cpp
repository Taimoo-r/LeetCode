
class Solution {
public:
    
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b); 
    }

    int maxPoints(vector<vector<int>>& p) {
        int n = p.size();
        if (n <= 2) return n; 

        int maxSize = 0; 
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slopes;
            for (int j = i + 1; j < n; ++j) {
                int dy = p[j][1] - p[i][1]; 
                int dx = p[j][0] - p[i][0]; 
                
                if (dx == 0) {
                    slopes["inf"]++; 
                } else {
                    int g = gcd(dy, dx);
                    dy /= g; 
                    dx /= g; 
                    if (dx < 0) { 
                        dy = -dy;
                        dx = -dx;
                    }
                    string slopeKey = to_string(dy) + "/" + to_string(dx);
                    slopes[slopeKey]++;
                }
            }
            
            for (const auto& [key, count] : slopes) {
                maxSize = max(maxSize, count + 1);
            }
        }
        return maxSize; // Return the maximum size found
    }
};
