class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        string curr = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0'); 
            }
            else if (c == '[') {
                countStack.push(k);
                strStack.push(curr);
                k = 0;
                curr = "";
            }
            else if (c == ']') {
                int times = countStack.top(); countStack.pop();
                string prev = strStack.top(); strStack.pop();
                while (times--) {
                    prev += curr;
                }
                curr = prev;
            }
            else {
                curr += c;
            }
        }

        return curr;
    }
};
