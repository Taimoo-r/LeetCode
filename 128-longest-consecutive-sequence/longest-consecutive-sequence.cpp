#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create an unordered_set from the vector to remove duplicates and allow O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int longest = 0;

        // Iterate through the numbers in the set
        for (const int& n : numSet) {
            // Check if 'n' is the start of a sequence
            if (numSet.find(n - 1) == numSet.end()) {
                int current = n;
                int currLong = 1;

                // Find the length of the sequence starting from 'n'
                while (numSet.find(current + 1) != numSet.end()) {
                    current += 1;
                    currLong += 1;
                }
                
                // Update the longest sequence found
                longest = max(longest, currLong);
            }
        }
        
        return longest;
    }
};
