#define ll long long
class Solution {
public:
    vector<string> addOperators(string num, int t) {
        string curr = "";
        vector<string> res;
        long long ans = 0;
        gen(num, t, curr, res, ans, 0, 0);
        return res;
    }

    void gen(string &num, int t, string curr, vector<string> &res, ll ans, int i, ll prev) {
        if (i == num.size()) {
            if(ans == t)
            res.push_back(curr);
            return;
        }
        if (i >= num.size()) return;
        for(int k  = i ; k < num.size() ; k++){
        
        string currStr = num.substr(i, k - i + 1);
        long long currNum = stoll(currStr);
        if(currStr.size() > 1 && currStr[0] == '0') break;

        if(i == 0)
        gen(num, t, currStr, res, ans + currNum , k + 1, currNum);
        else   {  
        gen(num, t, curr + "*" + currStr, res ,ans - prev + (prev * (currNum)), k + 1, currNum*prev);

        gen(num, t, curr + "+" + currStr, res, ans + currNum, k + 1, currNum);
        
        gen(num, t, curr + "-" + currStr, res, ans - currNum, k + 1, -currNum);
        }

        }
    }
};
