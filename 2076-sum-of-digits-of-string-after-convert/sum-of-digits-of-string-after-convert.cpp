class Solution {
public:
    int getLucky(string s, int k) {
        string integers = "";
        for (int i = 0; i < s.size(); i++) {
            integers += to_string((abs(97 - (int)s[i]) + 1));
        }
        int num = 1;
        while (k--){
            num = 0;
            for (int i = 0; i < integers.size(); i++) {
                num += integers[i] - 48;
            }
            integers = to_string(num);
        }
        return num;
    }
};