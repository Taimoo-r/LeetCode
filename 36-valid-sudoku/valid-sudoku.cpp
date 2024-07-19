class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        set<char> r;
        vector<set<char>> c(9),box(9);
        int n = b.size();
        for (int i = 0; i < n; i++) {
            r.clear();
            for (int j = 0; j < 9; j++) {
                // Validating Rows
                if (b[i][j] != '.') {
                    if (r.find(b[i][j]) != r.end())
                        return false;
                    else
                        r.insert(b[i][j]);

                    // Validating Columns
                    if (c[j].find(b[i][j]) != c[j].end())
                        return false;
                    else
                        c[j].insert(b[i][j]);
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    if (box[boxIndex].find(b[i][j]) != box[boxIndex].end())
                        return false;
                    else
                        box[boxIndex].insert(b[i][j]);
                }
            }
        }
        return true;
    }
};
