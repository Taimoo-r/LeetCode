// class Solution {
// public:
//     int countSubstrings(string s) {
//         int n = s.size();
//         int count = 0;
//         for(int i = 0 ; i < n; i++){
//             count++;
//             string temp = "";
//             temp+=s[i];
//             for(int j = i + 1 ; j < n ; j++){
//                 temp+=s[j];
//                 string rev = temp;
//                 reverse(rev.begin(), rev.end());
//                 if(rev==temp) count++;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        // Lambda to count palindromes from a center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; ++i) {
            // Odd-length palindromes (single character center)
            expandAroundCenter(i, i);
            // Even-length palindromes (two character center)
            expandAroundCenter(i, i + 1);
        }

        return count;
    }
};
